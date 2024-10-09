#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDebug>

TCPServer::TCPServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TCPServer)
    , tcpServer(new QTcpServer(this))       // Initializing the TCP server
    , clientSocket(nullptr)
{
    ui->setupUi(this);

    // Setup the UI
    ui->label_message->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->label_message->setWordWrap(true);

    // Manually connect the button click signal to the startServer slot
    connect(ui->startServer, &QPushButton::clicked, this, &TCPServer::startServer);
    connect(ui->sendButton, &QPushButton::clicked, this, &TCPServer::sendMessage);


    // Connecting signals for the TCP server
    connect(tcpServer, &QTcpServer::newConnection, this, &TCPServer::onNewConnection);
}

TCPServer::~TCPServer()
{
    delete ui;
}

// This function is triggered when the button is clicked
void TCPServer::startServer()
{
    // Start listening for connections on port 1234
    if(!tcpServer->listen(QHostAddress::Any, 1234)){
        ui->label->setText("Server failed to start!");
    } else {
        ui->label->setText("Server started, waiting for connection...");
        qDebug() << "Server started on port 1234";
    }
}

// This function is triggered when new client is connected
void TCPServer::onNewConnection()
{
    // Accept the connection
    clientSocket = tcpServer->nextPendingConnection();

    ui->label->setText("Client connected!");

    // Connect signals from the client socket to the server

    connect(clientSocket, &QTcpSocket::readyRead, this, &TCPServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TCPServer::onDisconnected);

    qDebug() << "Client connected!";
}

// This function handles incoming data from the client
void TCPServer::onReadyRead()
{
    if(clientSocket){
        // Read the data from the client
        QByteArray dataFromClient = clientSocket->readAll();
        QString receivedMessage = QString::fromUtf8(dataFromClient);
        qDebug() << "Received message:" << receivedMessage;

        // Displaying the message in the UI
        ui->label_message->setText("Received: " + receivedMessage);

        // Sending response back to client
        clientSocket->write("Message received!");
    }
}

// This function handles client disconnection
void TCPServer::onDisconnected()
{
    ui->label->setText("Client disconneted");
    clientSocket->deleteLater();                // Clean up the client socket
    clientSocket = nullptr;                     // Reset the pointer
    qDebug() << "Client disconnected";
}

// This function handles the portion for the data to the client
void TCPServer::sendMessage()
{
    QString message = ui->lineEdit->text();
    if (clientSocket && clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(message.toUtf8());
        ui->label_message->setText(ui->label_message->text() + "\nServer: " + message);
        ui->lineEdit->clear();
    }
}
