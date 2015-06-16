#include "zootabs.h"
#include "ui_zootabs.h"
#include "zootelnetwidget.h"

ZooTabs::ZooTabs(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ZooTabs)
{
    ui->setupUi(this);
}

ZooTabs::~ZooTabs()
{
    delete ui;
}

int ZooTabs::addServer(QString serverIp, QString port)
{
    ZooTelnetWidget *tab = new ZooTelnetWidget(this);
    tab->setServer(serverIp, port);
    // tryout stat command
    tab->socketWrite("stat");

    // add tab to TabView and return the new TabIndex
    return this->addTab(tab, serverIp + ":" + port);
}
