#include "menubar.h"
#include "ui_menubar.h"
#include "zoodialog.h"
#include "zootabs.h"
#include <QMenuBar>

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);
    initializeActions();
}

MenuBar::~MenuBar()
{
    delete ui;
}

void MenuBar::initializeActions()
{
    newZooAction = new QAction(tr("&New"), this);
    connect(newZooAction, SIGNAL(triggered()), this, SLOT(openZooDialog()));

    this->addAction(newZooAction);

}

void MenuBar::setTabView(ZooTabs *zooServerContainer)
{
    tabView = zooServerContainer;
}

void MenuBar::openZooDialog()
{
    ZooDialog zooDialog;
    zooDialog.show();

    // if dialog accepted
    if (zooDialog.exec() == 1) {
        tabView->setCurrentIndex(tabView->addServer(zooDialog.getServerAdress(), zooDialog.getServerPort()));
        qCritical("Menubar::openZooDialog : " + zooDialog.getServerAdress().toUtf8());
    }
}
