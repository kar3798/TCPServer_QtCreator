#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDebug>
#include <QDateTime>

TCPServer::TCPServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TCPServer)
    , tcpServer(new QTcpServer(this))       // Initializing the TCP server
    , clientSocket(nullptr)
    , serverRunning(false)                  // Initializing the server as not running
{
    ui->setupUi(this);

    // Setup the UI for chat history
    ui->chatHistory->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->chatHistory->setWordWrapMode(QTextOption::WordWrap);
    ui->chatHistory->setReadOnly(true);

    ui->label_instruction->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->label_instruction->setText("Type your message below:");

    ui->label_instruction_2->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    ui->label_instruction_2->setText("Press Enter or click Send");

    // Connecting    the start/stop button to the server control function
    connect(ui->startServer, &QPushButton::clicked, this, &TCPServer::startServer);
    connect(ui->sendButton, &QPushButton::clicked, this, &TCPServer::sendMessage);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &TCPServer::sendMessage); // Send on Enter key

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
    if (!serverRunning) {
        // Start the server
        if (!tcpServer->listen(QHostAddress::Any, 1234)) {
            ui->label->setText("Server failed to start!");
        } else {
            ui->label->setText("Server started, waiting for connection...");
            ui->startServer->setText("Stop Server");  // Change button text to "Stop Server"
            serverRunning = true;
            qDebug() << "Server started on port 1234";
        }
    } else {
        // Stop the server
        tcpServer->close();  // Stop listening for connections
        if (clientSocket) {
            clientSocket->disconnectFromHost();  // Disconnect any active clients
            clientSocket->close();
        }
        ui->label->setText("Server stopped.");
        ui->startServer->setText("Start Server");  // Change button text to "Start Server"
        serverRunning = false;
        qDebug() << "Server stopped";
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

        // Get current time for the timestamp
        QString timeStamp = QDateTime::currentDateTime().toString("hh:mm:ss");

        // Format and append client message with timestamp and color
        ui->chatHistory->append(QString("<font color='red'>[%1] <b>Client:</b> %2</font>")
                                    .arg(timeStamp, receivedMessage));
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

        // Get current time for the timestamp
        QString timeStamp = QDateTime::currentDateTime().toString("hh:mm:ss");

        // Format and append server message with timestamp and color
        ui->chatHistory->append(QString("<font color='green'>[%1] <b>Server:</b> %2</font>")
                                    .arg(timeStamp, message));

        ui->lineEdit->clear();
    }
}
