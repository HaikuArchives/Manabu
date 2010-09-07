#ifndef MANABUWINDOW_H
#define MANABUWINDOW_H

#include "ui_manabuwindow.h"
#include "../../PileManager.h"
#include <QtGui/QMainWindow>

#include <map>

class ManabuWindow : public QMainWindow
{
    Q_OBJECT

public:
                            ManabuWindow(QWidget *parent = 0);
                            ~ManabuWindow();
public slots:
    void                    SubmitClicked();
    void                    Quit();
    void                    OpenDeck();
private:
    Ui::fMainWindow         fWindow;
    map<int,PileManager*>   fDecks;
    int                     fCurrentDeck;
    list<Card*>             fOnDeck;

    void                    _CreatePile(int pileNum);
    void                    _ShowCard();
};

#endif // MANABUWINDOW_H
