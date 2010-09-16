#include "manabuwindow.h"
#include "editdeckwindow.h"
#include "ui_manabuwindow.h"

#include "../PileManager.h"
#include "../Utilities.h"

#include <QFileDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>

ManabuWindow::ManabuWindow(QWidget *parent)
    : QMainWindow(parent),
    fShowFront(true),
    fOnDeck(NULL)

{
    fWindow.setupUi(this);
    fWindow.fDeckSelector->setColumnCount(1);

    connect(fWindow.fAnswer, SIGNAL(returnPressed()), this, SLOT(SubmitClicked()));
    connect(fWindow.fActionExit, SIGNAL(triggered()), this, SLOT(Quit()));
    connect(fWindow.fActionOpen, SIGNAL(triggered()), this, SLOT(OpenDeck()));
    connect(fWindow.fDeckNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(PileIndexChanged(int)));
    connect(fWindow.fActionSaveDeck, SIGNAL(triggered()), this, SLOT(SaveDeck()));
    connect(fWindow.fDeckSelector, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(DeckClicked(QModelIndex)));
    connect(fWindow.fActionToggleDisplay, SIGNAL(triggered()), this, SLOT(ToggleDisplay()));
    connect(fWindow.fActionNewDeck, SIGNAL(triggered()), this, SLOT(NewDeck()));
    connect(fWindow.fActionEditCard, SIGNAL(triggered()), this, SLOT(EditCard()));
    connect(fWindow.fActionAddCard, SIGNAL(triggered()), this, SLOT(AddCard()));
    connect(fWindow.fActionEditDeck, SIGNAL(triggered()), this, SLOT(EditDeck()));

    OpenDeck();
}

ManabuWindow::~ManabuWindow()
{
    map<int,PileManager*>::iterator it;
    for (it=fDecks.begin(); it != fDecks.end(); it++) {
        PileManager* pile = (*it).second;
        delete pile;
    }
}

void
ManabuWindow::SubmitClicked()
{
    if (fOnDeck == NULL || fOnDeck->empty() || fDecks.empty())
        return;

    xmlChar *back;
    Card* card = fOnDeck->front();
    fOnDeck->pop_front();

    if (fShowFront) {
        card->GetBack(&back);
    } else {
        card->GetFront(&back);
    }


    if (strcasecmp(fWindow.fAnswer->text().toAscii(), (char*)back) == 0) {
        fWindow.fResult->setText("Correct!");
        PileManager* manager = fDecks[fCurrentDeck];
        card->SetPileNumber(card->PileNumber() + 1);
        manager->AddToPile(card, card->PileNumber());
    }
    else {
        QString str("Incorrect. The correct answer is, ");
        QString tmp((char*)back);
        str.append(tmp);
        fWindow.fResult->setText(str);
        PileManager* manager = fDecks[fCurrentDeck];
        card->SetPileNumber(card->PileNumber() - 1);
        manager->AddToPile(card, card->PileNumber());
    }

    _ShowCard();
    fWindow.fAnswer->setText("");
}


void
ManabuWindow::Quit()
{
    SaveDeck();
    this->close();
}


void
ManabuWindow::SaveDeck()
{
    if (fDecks.empty())
        return;

    PileManager* deck = fDecks[fCurrentDeck];
    WriteDeckFile("test.dkf", deck);
}

void
ManabuWindow::OpenDeck()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Deck"),
                QDir::currentPath(),
                tr("Document files (*.dkf *.xml);;All files (*.*)"),
                0);
    if(!filename.isNull())
    {
        PileManager* deck = new PileManager(5);
        ParseDeckFile(filename.toAscii(), deck);
        _AddMenuItem(deck);

        fWindow.fDeckNumber->clear();
        // TODO: This is a hardcoded hack. This info needs to come from fCurrentDeck
        QStringList piles;
        PileManager* manager = fDecks[fCurrentDeck];
        for (int i = 1; i <= manager->MaxPile(); i++) {
            QString str;
            piles << str.number(i, 10);
        }
        fWindow.fDeckNumber->addItems(piles);
        fWindow.fDeckNumber->setCurrentIndex(4);
    }
}


void
ManabuWindow::ToggleDisplay()
{
    fShowFront = !fShowFront;
    if (fOnDeck != NULL)
        _ShowCard();
}

void
ManabuWindow::PileIndexChanged(int index)
{
    fWindow.fResult->setText("");
    fCurrentPile = index + 1;
    _CreatePile(fCurrentPile);
    _ShowCard();
}


void
ManabuWindow::DeckClicked(QModelIndex index)
{
    fCurrentDeck = index.row();
    _CreatePile(fCurrentPile);
    // Clear the results texts. This needs to be clear when
    // a new deck is selected.
    fWindow.fResult->setText("");
    fPileSize = fOnDeck->size();
    fCurrentCard = 0;
    _ShowCard();
}


void
ManabuWindow::NewDeck()
{
    EditDeckWindow win(this);
    win.exec();
    if (win.result() == QDialog::Accepted) {
        PileManager* deck = new PileManager(5);
        deck->SetName((xmlChar*)win.Title().toAscii().constData());
        _AddMenuItem(deck);
    }
}

void
ManabuWindow::EditDeck()
{
    EditDeckWindow win(fDecks[fCurrentDeck], this);
    win.exec();
    if (win.result() == QDialog::Accepted) {
        fDecks[fCurrentDeck]->SetName((xmlChar*)win.Title()
                                      .toAscii().constData());
        fWindow.fDeckSelector->currentItem()->
                setText(0, QString((char*)fDecks[fCurrentDeck]->Name()));
    }
}

void
ManabuWindow::EditCard()
{

}

void
ManabuWindow::AddCard()
{

}


void
ManabuWindow::_CreatePile(int pileNum)
{
    PileManager* manager = fDecks[fCurrentDeck];
    manager->GetPile(&fOnDeck, pileNum);
    fPileSize = fOnDeck->size();
    fCurrentCard = 0;
}

void
ManabuWindow::_ShowCard()
{
    xmlChar* tmp;
    // If the deck is empty, get the pile again
    if (fOnDeck->empty()) {
        fWindow.fWord->setText("");
        fWindow.fResult->setText("There are no cards left in the selected pile");
        return;
    }

    // Check if we have gone through all the cards.
    if (fCurrentCard >= fPileSize) {
        QMessageBox::about(this, "Letting you know...", \
                           "You have run through all the cards in the " \
                           "pile.");
        fPileSize = fOnDeck->size();
        fCurrentCard = 0;
    } else {
        fCurrentCard++;
    }

    if (fShowFront) {
        Card* card = fOnDeck->front();
        card->GetFront(&tmp);
    } else {
        Card* card = fOnDeck->front();
        card->GetBack(&tmp);
    }
    fWindow.fWord->setText(tr((char*)tmp));
}

void
ManabuWindow::_AddMenuItem(PileManager* deck)
{
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, tr((char*)deck->Name()));
    int index = fWindow.fDeckSelector->topLevelItemCount();
    fWindow.fDeckSelector->insertTopLevelItem(index, item);
    fDecks[index] = deck;
    fCurrentDeck = index;
    fCurrentPile = 5;
    _CreatePile(5);
    _ShowCard();

    if (fWindow.fDeckSelector->topLevelItemCount() > 0) {
        fWindow.fActionEditDeck->setEnabled(true);
    }
}
