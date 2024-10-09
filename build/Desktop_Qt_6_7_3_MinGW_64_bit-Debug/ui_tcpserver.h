/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServer
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *startServer;
    QLabel *label_message;
    QPushButton *sendButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;

    void setupUi(QMainWindow *TCPServer)
    {
        if (TCPServer->objectName().isEmpty())
            TCPServer->setObjectName("TCPServer");
        TCPServer->resize(400, 400);
        centralwidget = new QWidget(TCPServer);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 380, 20));
        startServer = new QPushButton(centralwidget);
        startServer->setObjectName("startServer");
        startServer->setGeometry(QRect(30, 320, 140, 50));
        label_message = new QLabel(centralwidget);
        label_message->setObjectName("label_message");
        label_message->setGeometry(QRect(10, 40, 380, 230));
        label_message->setStyleSheet(QString::fromUtf8(""));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(230, 320, 140, 50));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 280, 380, 30));
        TCPServer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TCPServer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        TCPServer->setMenuBar(menubar);

        retranslateUi(TCPServer);

        QMetaObject::connectSlotsByName(TCPServer);
    } // setupUi

    void retranslateUi(QMainWindow *TCPServer)
    {
        TCPServer->setWindowTitle(QCoreApplication::translate("TCPServer", "TCPServer", nullptr));
        label->setText(QString());
        startServer->setText(QCoreApplication::translate("TCPServer", "Start Server", nullptr));
        label_message->setText(QString());
        sendButton->setText(QCoreApplication::translate("TCPServer", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPServer: public Ui_TCPServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
