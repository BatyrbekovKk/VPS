#include "server.h"
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent), socket(nullptr) {}

void Server::startServer() {
    if (this->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server started!";
    } else {
        qDebug() << "Server could not start!";
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
    qDebug() << "Client connected with descriptor:" << socketDescriptor;
}

void Server::onReadyRead() {
    QByteArray data = socket->readAll();
    qDebug() << "Received data:" << data;

    // Простой пример обработки данных
    if (data.startsWith("LOGIN")) {
        // Обработка логина
        // Например, отправка ответа об успешном логине
        socket->write("LOGIN_SUCCESS");
    } else if (data.startsWith("REGISTER")) {
        // Обработка регистрации
        // Например, отправка ответа об успешной регистрации
        socket->write("REGISTER_SUCCESS");
    }
}

void Server::onClientDisconnected() {
    qDebug() << "Client disconnected";
    socket->deleteLater();
}
