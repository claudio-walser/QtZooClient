#include "qtzooclient.h"
#include "ui_qtzooclient.h"
#include "settingsdialog.h"

QtZooClient::QtZooClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtZooClient)
{
    ui->setupUi(this);

    SettingsDialog settingsDialog;
    settingsDialog.show();
    settingsDialog.exec();
}

QtZooClient::~QtZooClient()
{
    delete ui;
}
