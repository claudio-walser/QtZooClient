#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QDialog>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
