#include "zootelnetwidget.h"
#include "ui_zootelnetwidget.h"

ZooTelnetWidget::ZooTelnetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZooTelnetWidget)
{
    ui->setupUi(this);
    setupTelnetCommands();
}

ZooTelnetWidget::~ZooTelnetWidget()
{
    delete ui;
}

void ZooTelnetWidget::setServer(QString &serverIp)
{
    server = &serverIp;
}

void ZooTelnetWidget::connect()
{
    //open a socket
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


    foreach(QString i, commandList.keys()) {
        qCritical(commandList.value(i).toUtf8());
    }

}
