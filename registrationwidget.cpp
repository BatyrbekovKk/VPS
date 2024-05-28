#include "registrationwidget.h"
#include "ui_registrationwidget.h"
#include <QMessageBox>
#include <QSqlError>

RegistrationWidget::RegistrationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationWidget),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    initDatabase();

    connect(ui->registerButton, &QPushButton::clicked, this, &RegistrationWidget::on_registerButton_clicked);
}

RegistrationWidget::~RegistrationWidget() {
    db.close();
    delete ui;
}

void RegistrationWidget::initDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");
    }

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
    }
}

void RegistrationWidget::on_registerButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Registration Failed", "Passwords do not match");
        return;
    }

    // Проверка на уникальность имени пользователя
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM users WHERE username = :username");
    checkQuery.bindValue(":username", username);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to check username: " + checkQuery.lastError().text());
        return;
    }

    if (checkQuery.next()) {
        QMessageBox::warning(this, "Registration Failed", "Username already exists");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        // Выводим текст ошибки, если запрос не выполнен
        QMessageBox::warning(this, "Registration Failed", "Failed to register user: " + query.lastError().text());
        return;
    } else {
        emit registrationSuccessful();
    }
}
