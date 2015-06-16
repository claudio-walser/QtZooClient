#ifndef ZOOTELNETWIDGET_H
#define ZOOTELNETWIDGET_H

#include <QWidget>
#include <QMap>
#include <QTcpSocket>

namespace Ui {
class ZooTelnetWidget;
}

class ZooTelnetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZooTelnetWidget(QWidget *parent = 0);
    ~ZooTelnetWidget();
    void setServer(QString serverIp, QString port);
    void connect();
    void setupTelnetCommands();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void socketWrite(QString string);

private:
    Ui::ZooTelnetWidget *ui;
    QTcpSocket *socket;
    QString server;
    QString port;
    QMap<QString, QString> commandList;
};

#endif // ZOOTELNETWIDGET_H
