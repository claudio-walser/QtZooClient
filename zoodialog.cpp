#include "zoodialog.h"
#include "ui_zoodialog.h"
#include <QDialog>

ZooDialog::ZooDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZooDialog)
{
    ui->setupUi(this);

}

ZooDialog::~ZooDialog()
{
    delete ui;
}

QString ZooDialog::getServerAdress()
{
    return ui->lineEdit->text();
}
