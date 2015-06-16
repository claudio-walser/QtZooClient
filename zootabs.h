#ifndef ZOOTABS_H
#define ZOOTABS_H

#include <QTabWidget>

namespace Ui {
class ZooTabs;
}

class ZooTabs : public QTabWidget
{
    Q_OBJECT

public:
    explicit ZooTabs(QWidget *parent = 0);
    ~ZooTabs();
    int addServer(QString serverIp, QString port);

private:
    Ui::ZooTabs *ui;
};

#endif // ZOOTABS_H
