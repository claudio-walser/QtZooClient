#ifndef QTZOOCLIENT_H
#define QTZOOCLIENT_H

#include <QMainWindow>
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
private slots:
    void openZooDialog();
private:
    Ui::QtZooClient *ui;
    ZooTabs *zooServerContainer;
};

#endif // QTZOOCLIENT_H
