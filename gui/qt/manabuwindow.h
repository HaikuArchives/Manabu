#ifndef MANABUWINDOW_H
#define MANABUWINDOW_H

#include "../../qt/ui_manabuwindow.h"
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
    void                    SaveDeck();
    void                    PileIndexChanged(int index);
    void                    DeckClicked(QModelIndex);
    void                    ToggleDisplay();
private:
    Ui::fMainWindow         fWindow;
    map<int,PileManager*>   fDecks;
    int                     fCurrentDeck;
    int                     fCurrentPile;
    int                     fPileSize;
    int                     fCurrentCard;
    bool                    fShowFront;
    list<Card*>*            fOnDeck;

    void                    _CreatePile(int pileNum);
    void                    _ShowCard();
};

#endif // MANABUWINDOW_H
