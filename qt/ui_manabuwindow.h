/********************************************************************************
** Form generated from reading UI file 'manabuwindow.ui'
**
** Created: Tue Sep 14 12:31:54 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANABUWINDOW_H
#define UI_MANABUWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fMainWindow
{
public:
    QAction *fActionOpen;
    QAction *fActionExit;
    QAction *fActionSaveDeck;
    QAction *fActionToggleDisplay;
    QWidget *fCentralWidget;
    QGridLayout *gridLayout;
    QTreeWidget *fDeckSelector;
    QLineEdit *fAnswer;
    QComboBox *fDeckNumber;
    QLabel *fResult;
    QLabel *fWord;
    QMenuBar *fMenuBar;
    QMenu *fMenuFile;
    QMenu *fMenuDeck;
    QStatusBar *fStatusBar;

    void setupUi(QMainWindow *fMainWindow)
    {
        if (fMainWindow->objectName().isEmpty())
            fMainWindow->setObjectName(QString::fromUtf8("fMainWindow"));
        fMainWindow->resize(649, 355);
        fActionOpen = new QAction(fMainWindow);
        fActionOpen->setObjectName(QString::fromUtf8("fActionOpen"));
        fActionExit = new QAction(fMainWindow);
        fActionExit->setObjectName(QString::fromUtf8("fActionExit"));
        fActionSaveDeck = new QAction(fMainWindow);
        fActionSaveDeck->setObjectName(QString::fromUtf8("fActionSaveDeck"));
        fActionToggleDisplay = new QAction(fMainWindow);
        fActionToggleDisplay->setObjectName(QString::fromUtf8("fActionToggleDisplay"));
        fCentralWidget = new QWidget(fMainWindow);
        fCentralWidget->setObjectName(QString::fromUtf8("fCentralWidget"));
        gridLayout = new QGridLayout(fCentralWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fDeckSelector = new QTreeWidget(fCentralWidget);
        fDeckSelector->setObjectName(QString::fromUtf8("fDeckSelector"));
        fDeckSelector->setMinimumSize(QSize(313, 0));

        gridLayout->addWidget(fDeckSelector, 0, 0, 6, 1);

        fAnswer = new QLineEdit(fCentralWidget);
        fAnswer->setObjectName(QString::fromUtf8("fAnswer"));

        gridLayout->addWidget(fAnswer, 5, 2, 1, 1);

        fDeckNumber = new QComboBox(fCentralWidget);
        fDeckNumber->setObjectName(QString::fromUtf8("fDeckNumber"));

        gridLayout->addWidget(fDeckNumber, 5, 5, 1, 1);

        fResult = new QLabel(fCentralWidget);
        fResult->setObjectName(QString::fromUtf8("fResult"));

        gridLayout->addWidget(fResult, 2, 2, 1, 3);

        fWord = new QLabel(fCentralWidget);
        fWord->setObjectName(QString::fromUtf8("fWord"));

        gridLayout->addWidget(fWord, 1, 2, 1, 1);

        fMainWindow->setCentralWidget(fCentralWidget);
        fMenuBar = new QMenuBar(fMainWindow);
        fMenuBar->setObjectName(QString::fromUtf8("fMenuBar"));
        fMenuBar->setGeometry(QRect(0, 0, 649, 25));
        fMenuFile = new QMenu(fMenuBar);
        fMenuFile->setObjectName(QString::fromUtf8("fMenuFile"));
        fMenuDeck = new QMenu(fMenuBar);
        fMenuDeck->setObjectName(QString::fromUtf8("fMenuDeck"));
        fMainWindow->setMenuBar(fMenuBar);
        fStatusBar = new QStatusBar(fMainWindow);
        fStatusBar->setObjectName(QString::fromUtf8("fStatusBar"));
        fMainWindow->setStatusBar(fStatusBar);

        fMenuBar->addAction(fMenuFile->menuAction());
        fMenuBar->addAction(fMenuDeck->menuAction());
        fMenuFile->addAction(fActionOpen);
        fMenuFile->addAction(fActionSaveDeck);
        fMenuFile->addAction(fActionExit);
        fMenuDeck->addAction(fActionToggleDisplay);

        retranslateUi(fMainWindow);

        QMetaObject::connectSlotsByName(fMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *fMainWindow)
    {
        fMainWindow->setWindowTitle(QApplication::translate("fMainWindow", "Manabu", 0, QApplication::UnicodeUTF8));
        fActionOpen->setText(QApplication::translate("fMainWindow", "Open", 0, QApplication::UnicodeUTF8));
        fActionExit->setText(QApplication::translate("fMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        fActionSaveDeck->setText(QApplication::translate("fMainWindow", "Save Deck", 0, QApplication::UnicodeUTF8));
        fActionToggleDisplay->setText(QApplication::translate("fMainWindow", "Display Back", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = fDeckSelector->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("fMainWindow", "Decks", 0, QApplication::UnicodeUTF8));
        fResult->setText(QString());
        fWord->setText(QString());
        fMenuFile->setTitle(QApplication::translate("fMainWindow", "File", 0, QApplication::UnicodeUTF8));
        fMenuDeck->setTitle(QApplication::translate("fMainWindow", "Deck", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fMainWindow: public Ui_fMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANABUWINDOW_H
