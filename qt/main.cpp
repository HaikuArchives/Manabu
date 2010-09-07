#include <QtGui/QApplication>
#include "../gui/qt/manabuwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ManabuWindow w;
    w.show();
    return a.exec();
}
