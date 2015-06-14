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

int ZooTabs::addServer(QString serverIp)
{
    ZooTelnetWidget *tab = new ZooTelnetWidget(this);
    tab->setServer(&serverIp);
    return this->addTab(tab, serverIp);
}
