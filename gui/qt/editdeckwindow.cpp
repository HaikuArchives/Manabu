#include "editdeckwindow.h"
#include "ui_editdeckwindow.h"

EditDeckWindow::EditDeckWindow(QWidget *parent) :
    QDialog(parent),
    fWindow(new Ui::editdeckwindow)
{
    _Init();
}

EditDeckWindow::EditDeckWindow(PileManager* pile, QWidget *parent)
    :
    QDialog(parent),
    fWindow(new Ui::editdeckwindow)
{
    _Init();
    fWindow->fTitle->setText(QString((char*)pile->Name()));
}

EditDeckWindow::~EditDeckWindow()
{
    delete fWindow;
}

void
EditDeckWindow::ChangeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        fWindow->retranslateUi(this);
        break;
    default:
        break;
    }
}

void
EditDeckWindow::OkClicked()
{
    _ResetTitles();
    if (!_IsValid())
        return;
    this->setResult(QDialog::Accepted);
    this->hide();
}

void
EditDeckWindow::CancelClicked()
{
    this->setResult(QDialog::Rejected);
    this->hide();
}

QString
EditDeckWindow::Title()
{
    return fWindow->fTitle->text();
}

QString
EditDeckWindow::Author()
{
    return fWindow->fAuthor->text();
}

QString
EditDeckWindow::Description()
{
    return fWindow->fDescription->text();
}

void
EditDeckWindow::_ResetTitles()
{
    fWindow->fAuthorLabel->setText("Author:");
    fWindow->fDescriptionLabel->setText("Description:");
    fWindow->fTitleLabel->setText("Title:");
}

bool
EditDeckWindow::_IsValid()
{
    QString str = fWindow->fTitle->text();
    if (str.count() < 1) {
        fWindow->fTitleLabel->setText(fWindow->fTitleLabel->text().append(
                                      " - This field cannot be blank"));
        return false;
    }
    return true;
}

void
EditDeckWindow::_Init()
{
    fWindow->setupUi(this);
    connect(fWindow->fButtonBox, SIGNAL(accepted()), this, SLOT(OkClicked()));
    connect(fWindow->fButtonBox, SIGNAL(rejected()), this, SLOT(CancelClicked()));
}


