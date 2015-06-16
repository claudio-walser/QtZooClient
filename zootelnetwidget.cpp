#include "zootelnetwidget.h"
#include "ui_zootelnetwidget.h"
#include "zoocommandbutton.h"
#include <QTcpSocket>
#include <QPushButton>
#include <QSignalMapper>

ZooTelnetWidget::ZooTelnetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZooTelnetWidget)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    setupTelnetCommands();
}

ZooTelnetWidget::~ZooTelnetWidget()
{
    socket->close();
    delete socket;
    delete ui;
}

void ZooTelnetWidget::setServer(QString serverIp, QString serverPort)
{
    server = serverIp;
    port = serverPort;
}

void ZooTelnetWidget::connect()
{
    QObject::connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    QObject::connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    QObject::connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    QObject::connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    socket->connectToHost(server, port.toInt());
    if(!socket->waitForConnected(5000)) {
        qCritical() << "ZooTelnetWidget::connect : " << socket->errorString() << " before-server-" << server << "-after server";
    }
}

void ZooTelnetWidget::setupTelnetCommands()
{
    commandList.insert("stat", "Lists brief details for the server and connected clients.");
    commandList.insert("conf", "New in 3.3.0: Print details about serving configuration.");
    commandList.insert("cons", "New in 3.3.0: List full connection/session details for all clients connected to this server. Includes information on numbers of packets received/sent, session id, operation latencies, last operation performed, etc...");
    commandList.insert("crst", "New in 3.3.0: Reset connection/session statistics for all connections.");
    commandList.insert("dump", "Lists the outstanding sessions and ephemeral nodes. This only works on the leader.");
    commandList.insert("envi", "Print details about serving environment");
    commandList.insert("ruok", "Tests if server is running in a non-error state. The server will respond with imok if it is running. Otherwise it will not respond at all.\nA response of 'imok' does not necessarily indicate that the server has joined the quorum, just that the server process is active and bound to the specified client port. Use 'stat' for details on state wrt quorum and client connection information.");
    commandList.insert("srst", "Reset server statistics.");
    commandList.insert("srvr", "New in 3.3.0: Lists full details for the server.");
    commandList.insert("wchs", "New in 3.3.0: Lists brief information on watches for the server.");
    commandList.insert("wchc", "New in 3.3.0: Lists detailed information on watches for the server, by session. This outputs a list of sessions(connections) with associated watches (paths). Note, depending on the number of watches this operation may be expensive (ie impact server performance), use it carefully.");
    commandList.insert("wchp", "New in 3.3.0: Lists detailed information on watches for the server, by path. This outputs a list of paths (znodes) with associated sessions. Note, depending on the number of watches this operation may be expensive (ie impact server performance), use it carefully.");

    int count = 0;
    foreach(QString i, commandList.keys()) {
        ZooCommandButton *btn = new ZooCommandButton();
        btn->setText(i);
        btn->setToolTip(commandList.value(i));

        // dammit i go most probably to extend QPushButton today evening and create my own signal to pass the current command
        QObject::connect(btn, SIGNAL(clicked()),this, SLOT(socketWrite()));

        /*
        // Map Signal to pass additional params
        QSignalMapper mapper;
        QObject::connect(btn, SIGNAL(released()), &mapper, SLOT(map()));
        mapper.setMapping(btn, i); // Number to be passed in the slot
        QObject::connect(&mapper, SIGNAL(mapped(QString)), this, SLOT(socketWrite()));*/

        ui->buttonLayout->addWidget(btn, 1, count);
        ++count;
    }
}

/*
 * slots
 */
void ZooTelnetWidget::socketWrite(QString string)
{
    socket->write(string.toUtf8());
}

void ZooTelnetWidget::socketWrite()
{
    qCritical() << "damn you QPushButton - get the clicked button anyhow?? " << this;
}

void ZooTelnetWidget::connected()
{
    qCritical() << "ZooTelnetWidget::connected : " << "connected...";
}

void ZooTelnetWidget::disconnected()
{
    qCritical() << "ZooTelnetWidget::disconnected : " << "disconnected...";
}

void ZooTelnetWidget::bytesWritten(qint64 bytes)
{
    qCritical() << "ZooTelnetWidget::bytesWritten : " << bytes << " bytes written...";
}

void ZooTelnetWidget::readyRead()
{
    ui->output->append(socket->readAll());
}
