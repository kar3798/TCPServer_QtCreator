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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServer
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *startServer;
    QPushButton *sendButton;
    QLineEdit *lineEdit;
    QTextEdit *chatHistory;
    QLabel *label_instruction;
    QLabel *label_instruction_2;
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
        startServer->setGeometry(QRect(10, 340, 140, 50));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(250, 340, 140, 50));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 290, 380, 30));
        chatHistory = new QTextEdit(centralwidget);
        chatHistory->setObjectName("chatHistory");
        chatHistory->setGeometry(QRect(10, 30, 380, 230));
        label_instruction = new QLabel(centralwidget);
        label_instruction->setObjectName("label_instruction");
        label_instruction->setGeometry(QRect(10, 270, 380, 20));
        label_instruction_2 = new QLabel(centralwidget);
        label_instruction_2->setObjectName("label_instruction_2");
        label_instruction_2->setGeometry(QRect(250, 320, 140, 20));
        TCPServer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TCPServer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 17));
        TCPServer->setMenuBar(menubar);

        retranslateUi(TCPServer);

        QMetaObject::connectSlotsByName(TCPServer);
    } // setupUi

    void retranslateUi(QMainWindow *TCPServer)
    {
        TCPServer->setWindowTitle(QCoreApplication::translate("TCPServer", "TCPServer", nullptr));
        label->setText(QString());
        startServer->setText(QCoreApplication::translate("TCPServer", "Start Server", nullptr));
        sendButton->setText(QCoreApplication::translate("TCPServer", "Send", nullptr));
        label_instruction->setText(QString());
        label_instruction_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TCPServer: public Ui_TCPServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
