#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    initDatabase();

    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWidget::on_loginButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWidget::on_registerButton_clicked);
}

LoginWidget::~LoginWidget() {
    db.close();
    delete ui;
}

void LoginWidget::initDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");
    }

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT NOT NULL UNIQUE, "
                    "password TEXT NOT NULL)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void LoginWidget::on_loginButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QString storedPassword = query.value(0).toString();
        if (storedPassword == password) {
            QMessageBox::information(this, "Login Successful", "You have successfully logged in.");
            emit loginSuccessful();
        } else {
            QMessageBox::warning(this, "Login Failed", "Incorrect password");
        }
    } else {
        QMessageBox::warning(this, "Login Failed", "User not found");
    }
}

void LoginWidget::on_registerButton_clicked() {
    emit registerClicked();
}
