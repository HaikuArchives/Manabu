/********************************************************************************
** Form generated from reading UI file 'manabuwindow.ui'
**
** Created: Mon Sep 6 23:52:03 2010
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fMainWindow
{
public:
    QAction *fActionOpen;
    QAction *fActionExit;
    QWidget *fCentralWidget;
    QGridLayout *gridLayout;
    QLabel *fWord;
    QLineEdit *fAnswer;
    QPushButton *fSubmit;
    QLabel *fResult;
    QTreeWidget *fDeckSelector;
    QMenuBar *fMenuBar;
    QMenu *fMenuFile;
    QStatusBar *fStatusBar;

    void setupUi(QMainWindow *fMainWindow)
    {
        if (fMainWindow->objectName().isEmpty())
            fMainWindow->setObjectName(QString::fromUtf8("fMainWindow"));
        fMainWindow->resize(649, 541);
        fActionOpen = new QAction(fMainWindow);
        fActionOpen->setObjectName(QString::fromUtf8("fActionOpen"));
        fActionExit = new QAction(fMainWindow);
        fActionExit->setObjectName(QString::fromUtf8("fActionExit"));
        fCentralWidget = new QWidget(fMainWindow);
        fCentralWidget->setObjectName(QString::fromUtf8("fCentralWidget"));
        gridLayout = new QGridLayout(fCentralWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fWord = new QLabel(fCentralWidget);
        fWord->setObjectName(QString::fromUtf8("fWord"));

        gridLayout->addWidget(fWord, 0, 1, 1, 1);

        fAnswer = new QLineEdit(fCentralWidget);
        fAnswer->setObjectName(QString::fromUtf8("fAnswer"));

        gridLayout->addWidget(fAnswer, 2, 1, 1, 1);

        fSubmit = new QPushButton(fCentralWidget);
        fSubmit->setObjectName(QString::fromUtf8("fSubmit"));
        fSubmit->setDefault(true);

        gridLayout->addWidget(fSubmit, 3, 1, 1, 1);

        fResult = new QLabel(fCentralWidget);
        fResult->setObjectName(QString::fromUtf8("fResult"));

        gridLayout->addWidget(fResult, 1, 1, 1, 1);

        fDeckSelector = new QTreeWidget(fCentralWidget);
        fDeckSelector->setObjectName(QString::fromUtf8("fDeckSelector"));
        fDeckSelector->setMinimumSize(QSize(313, 0));

        gridLayout->addWidget(fDeckSelector, 0, 0, 4, 1);

        fMainWindow->setCentralWidget(fCentralWidget);
        fMenuBar = new QMenuBar(fMainWindow);
        fMenuBar->setObjectName(QString::fromUtf8("fMenuBar"));
        fMenuBar->setGeometry(QRect(0, 0, 649, 23));
        fMenuFile = new QMenu(fMenuBar);
        fMenuFile->setObjectName(QString::fromUtf8("fMenuFile"));
        fMainWindow->setMenuBar(fMenuBar);
        fStatusBar = new QStatusBar(fMainWindow);
        fStatusBar->setObjectName(QString::fromUtf8("fStatusBar"));
        fMainWindow->setStatusBar(fStatusBar);

        fMenuBar->addAction(fMenuFile->menuAction());
        fMenuFile->addAction(fActionOpen);
        fMenuFile->addAction(fActionExit);

        retranslateUi(fMainWindow);

        QMetaObject::connectSlotsByName(fMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *fMainWindow)
    {
        fMainWindow->setWindowTitle(QApplication::translate("fMainWindow", "Manabu", 0, QApplication::UnicodeUTF8));
        fActionOpen->setText(QApplication::translate("fMainWindow", "Open", 0, QApplication::UnicodeUTF8));
        fActionExit->setText(QApplication::translate("fMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        fWord->setText(QString());
        fSubmit->setText(QApplication::translate("fMainWindow", "Submit", 0, QApplication::UnicodeUTF8));
        fResult->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = fDeckSelector->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("fMainWindow", "Decks", 0, QApplication::UnicodeUTF8));
        fMenuFile->setTitle(QApplication::translate("fMainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fMainWindow: public Ui_fMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANABUWINDOW_H
