#include "qtzooclient.h"
#include "ui_qtzooclient.h"
#include "zootabs.h"
#include "zoodialog.h"

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
    QAction *newZooAction = new QAction(tr("&New"), ui->menuBar);

    connect(newZooAction, SIGNAL(triggered()), this, SLOT(openZooDialog()));
    ui->menuBar->setNativeMenuBar(false);
    ui->menuBar->addAction(newZooAction);

    statusBar()->showMessage(tr("ui is ready"));
}

void QtZooClient::openZooDialog()
{
    ZooDialog zooDialog;
    zooDialog.show();

    // if dialog accepted
    if (zooDialog.exec() == 1) {
        ui->centralWidget->setCurrentIndex(ui->centralWidget->addServer(zooDialog.getServerAdress(), zooDialog.getServerPort()));
        qCritical("Menubar::openZooDialog : " + zooDialog.getServerAdress().toUtf8());
    }
}
