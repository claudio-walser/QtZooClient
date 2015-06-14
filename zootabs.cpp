#include "zootabs.h"
#include "ui_zootabs.h"

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

void ZooTabs::addServer(QString serverIp)
{

    this->addTab(new QTabWidget(this), serverIp);
}
