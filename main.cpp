#include <QApplication>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Запуск сервера
    Server server;
    server.startServer();

    MainWindow w;
    w.show();
    return a.exec();
}
