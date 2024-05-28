#ifndef REGISTRATIONWIDGET_H
#define REGISTRATIONWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class RegistrationWidget;
}

class RegistrationWidget : public QWidget {
    Q_OBJECT

public:
    explicit RegistrationWidget(QWidget *parent = nullptr);
    ~RegistrationWidget();

signals:
    void registrationSuccessful();

private slots:
    void on_registerButton_clicked();

private:
    void initDatabase();
    Ui::RegistrationWidget *ui;
    QTcpSocket *socket;
    QSqlDatabase db;
};

#endif // REGISTRATIONWIDGET_H
