# -------------------------------------------------
# Project created by QtCreator 2010-09-06T21:45:56
# -------------------------------------------------
TARGET = Manabu-qt
TEMPLATE = app
SOURCES += main.cpp \
    ../gui/qt/manabuwindow.cpp \
    ../Utilities.cpp \
    ../PileManager.cpp \
    ../Card.cpp \
    ../gui/qt/editdeckwindow.cpp
HEADERS += manabuwindow.h \
    ../gui/qt/manabuwindow.h \
    ../Utilities.h \
    ../PileManager.h \
    ../config.h \
    ../Card.h \
    ../gui/qt/editdeckwindow.h
FORMS += ../gui/qt/manabuwindow.ui \
    ../gui/qt/editcardwindow.ui \
    ../gui/qt/editdeckwindow.ui
CONFIG += link_pkgconfig
PKGCONFIG += libxml-2.0
