#include "qtzooclient.h"
#include "ui_qtzooclient.h"
#include "zoodialog.h"
#include "menubar.h"
#include "zootabs.h"

QtZooClient::QtZooClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtZooClient)
{
    ui->setupUi(this);
    this->initUi();
    this->initSignals();

    // crashes with sigsegv - probably cause the tabview isnt rendered yet
    //this->addServer(tr("10.20.0.40"));
}

QtZooClient::~QtZooClient()
{
    delete ui;
}

void QtZooClient::initUi()
{
    menuBar = new MenuBar(this);

    this->setMenuBar(menuBar);

    zooServerContainer = new ZooTabs(this->centralWidget());
    menuBar->setTabView(zooServerContainer);
    statusBar()->showMessage(tr("ui is ready"));
}

void QtZooClient::initSignals()
{

}

void QtZooClient::openZooDialog()
{
    ZooDialog zooDialog;
    zooDialog.show();
    zooDialog.exec();
}
