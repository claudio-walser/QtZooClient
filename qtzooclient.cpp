#include "qtzooclient.h"
#include "ui_qtzooclient.h"
#include "menubar.h"
#include "zootabs.h"

QtZooClient::QtZooClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtZooClient)
{
    ui->setupUi(this);
    this->initUi();
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
