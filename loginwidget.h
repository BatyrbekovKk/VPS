#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSqlDatabase>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

signals:
    void loginSuccessful();
    void registerClicked();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    void initDatabase();

    Ui::LoginWidget *ui;
    QTcpSocket *socket;
    QSqlDatabase db;
};

#endif // LOGINWIDGET_H
