#include "manabuwindow.h"
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

ManabuWindow::ManabuWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fWindow.setupUi(this);
    fWindow.fDeckSelector->setColumnCount(1);
    OpenDeck();
    connect(fWindow.fAnswer, SIGNAL(returnPressed()), this, SLOT(SubmitClicked()));
    connect(fWindow.fActionExit, SIGNAL(triggered()), this, SLOT(Quit()));
    connect(fWindow.fActionOpen, SIGNAL(triggered()), this, SLOT(OpenDeck()));
    connect(fWindow.fDeckNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(PileIndexChanged(int)));
}

ManabuWindow::~ManabuWindow()
{

}

void
ManabuWindow::SubmitClicked()
{
    if (fOnDeck->empty() || fDecks.empty())
        return;
    xmlChar *back;
    Card* card = fOnDeck->front();
    fOnDeck->pop_front();
    card->GetBack(&back);

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
    this->close();
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
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, tr((char*)deck->Name()));
        int index = fWindow.fDeckSelector->topLevelItemCount();
        fWindow.fDeckSelector->insertTopLevelItem(index, item);
        fDecks[index] = deck;
        fCurrentDeck = index;
        fCurrentPile = 5;
        _CreatePile(5);
        _ShowCard();

        QStringList piles;
        piles << "1" << "2" << "3" << "4" << "5";
        fWindow.fDeckNumber->addItems(piles);
        fWindow.fDeckNumber->setCurrentIndex(4);
    }
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
ManabuWindow::_CreatePile(int pileNum)
{
    PileManager* manager = fDecks[fCurrentDeck];
    manager->GetPile(&fOnDeck, pileNum);
}

void
ManabuWindow::_ShowCard()
{
    xmlChar* tmp;
    if (fOnDeck->empty()) {
        // TODO: This needs to not be hard coded.
        _CreatePile(fCurrentPile);
    }

    if (fOnDeck->empty()) {
        fWindow.fWord->setText("");
        fWindow.fResult->setText("There are no cards left in the selected pile");
        return;
    }

    Card* card = fOnDeck->front();
    card->GetFront(&tmp);

    fWindow.fWord->setText(tr((char*)tmp));
}
