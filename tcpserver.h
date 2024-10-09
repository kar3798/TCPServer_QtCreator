#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class TCPServer;
}
QT_END_NAMESPACE

class TCPServer : public QMainWindow
{
    Q_OBJECT

public:
    TCPServer(QWidget *parent = nullptr);
    ~TCPServer();

private slots:
    void startServer();                // Start server
    void onNewConnection();            // Handle new connections
    void onReadyRead();                // Handle incoming messages
    void onDisconnected();             // Handle client disconnection
    void sendMessage();                // Send message to the client

private:
    Ui::TCPServer *ui;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
};
#endif // TCPSERVER_H
