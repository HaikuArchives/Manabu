#ifndef EDITDECKWINDOW_H
#define EDITDECKWINDOW_H

#include "../../PileManager.h"

#include <QDialog>

namespace Ui {
    class editdeckwindow;
}

class EditDeckWindow : public QDialog {
    Q_OBJECT
public:
    EditDeckWindow(QWidget *parent = 0);
    EditDeckWindow(PileManager* pile, QWidget *parent = 0);
    ~EditDeckWindow();
    QString Title();
    QString Author();
    QString Description();
public slots:
    void OkClicked();
    void CancelClicked();
protected:
    void ChangeEvent(QEvent *e);

private:
    Ui::editdeckwindow *fWindow;
    void _ResetTitles();
    bool _IsValid();
    void _Init();
};

#endif // EDITDECKWINDOW_H
