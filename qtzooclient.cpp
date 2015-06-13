#include "qtzooclient.h"
#include "ui_qtzooclient.h"
#include "settingsdialog.h"
#include "menubar.h"

QtZooClient::QtZooClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtZooClient)
{
    ui->setupUi(this);
    this->initUi();


    // tryout settings dialog
    /*SettingsDialog settingsDialog;
    settingsDialog.show();
    settingsDialog.exec();*/
}

QtZooClient::~QtZooClient()
{
    delete ui;
}

void QtZooClient::initUi()
{
    MenuBar* menuBar = new MenuBar(this);
    this->setMenuBar(menuBar);
}
