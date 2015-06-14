#ifndef QTZOOCLIENT_H
#define QTZOOCLIENT_H

#include <QMainWindow>
#include "menubar.h"
#include "zootabs.h"

namespace Ui {
class QtZooClient;
}

class QtZooClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtZooClient(QWidget *parent = 0);
    ~QtZooClient();
    void initUi();
    void initSignals();
    void openZooDialog();
private:
    Ui::QtZooClient *ui;
    MenuBar *menuBar;
    ZooTabs *zooServerContainer;
};

#endif // QTZOOCLIENT_H
