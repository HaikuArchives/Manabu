#include "manabuwindow.h"
#include "ui_manabuwindow.h"

#include "../PileManager.h"
#include "../Utilities.h"

#include <QFileDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ManabuWindow::ManabuWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fWindow.setupUi(this);
    fWindow.fDeckSelector->setColumnCount(1);
    connect(fWindow.fSubmit, SIGNAL(clicked()), this, SLOT(SubmitClicked()));
    connect(fWindow.fAnswer, SIGNAL(returnPressed()), this, SLOT(SubmitClicked()));
    connect(fWindow.fActionExit, SIGNAL(triggered()), this, SLOT(Quit()));
    connect(fWindow.fActionOpen, SIGNAL(triggered()), this, SLOT(OpenDeck()));

    OpenDeck();
}

ManabuWindow::~ManabuWindow()
{

}

void
ManabuWindow::SubmitClicked()
{
    if (fDecks.empty())
        return;
    xmlChar *back;
    Card* card = fOnDeck.front();
    fOnDeck.pop_front();
    card->GetBack(&back);

    if (strcasecmp(fWindow.fAnswer->text().toAscii(), (char*)back) == 0) {
        fWindow.fResult->setText("Correct!");
    }
    else {
        fWindow.fResult->setText("Incorrect.");
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
                0, QFileDialog::DontUseNativeDialog);
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
        _CreatePile(5);
        _ShowCard();
    }
}


void
ManabuWindow::_CreatePile(int pileNum)
{
    list<Card*>* deck;
    PileManager* manager = fDecks[fCurrentDeck];
    manager->GetPile(&deck, pileNum);
    fOnDeck = *deck;
}

void
ManabuWindow::_ShowCard()
{
    xmlChar* tmp;
    if (fOnDeck.empty()) {
        // TODO: This needs to not be hard coded.
        _CreatePile(5);
    }

    Card* card = fOnDeck.front();
    card->GetFront(&tmp);

    fWindow.fWord->setText(tr((char*)tmp));
}
