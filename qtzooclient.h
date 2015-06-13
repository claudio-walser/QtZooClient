#ifndef QTZOOCLIENT_H
#define QTZOOCLIENT_H

#include <QMainWindow>
#include "menubar.h"

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
private:
    Ui::QtZooClient *ui;
    MenuBar* menuBar;
};

#endif // QTZOOCLIENT_H
