#ifndef ZOOTELNETWIDGET_H
#define ZOOTELNETWIDGET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class ZooTelnetWidget;
}

class ZooTelnetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZooTelnetWidget(QWidget *parent = 0);
    ~ZooTelnetWidget();
    void setServer(QString &serverIp);
    void connect();
    void setupTelnetCommands();

private:
    Ui::ZooTelnetWidget *ui;
    QString *server;
    QMap<QString, QString> commandList;
};

#endif // ZOOTELNETWIDGET_H
