#include "customer_dashboard_widget.h"
#include "ui_customer_dashboard_widget.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QInputDialog>

CustomerDashboardWidget::CustomerDashboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDashboardWidget),
    ordersModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    initDatabase();

    connect(ui->createOrderButton, &QPushButton::clicked, this, &CustomerDashboardWidget::on_createOrderButton_clicked);
}

CustomerDashboardWidget::~CustomerDashboardWidget()
{
    db.close();
    delete ui;
}

void CustomerDashboardWidget::initDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("logistics.db");
    }

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS orders ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "customer TEXT NOT NULL, "
               "mass REAL, "
               "volume REAL, "
               "type TEXT, "
               "start_point TEXT, "
               "end_point TEXT)");

    loadOrders();
}

void CustomerDashboardWidget::setCustomerName(const QString &name) {
    customerName = name;
    ui->customerNameLabel->setText("Welcome, " + name);
    loadOrders();
}

void CustomerDashboardWidget::loadOrders() {
    QSqlQuery query;
    query.prepare("SELECT id, mass, volume, type, start_point, end_point FROM orders WHERE customer = :customer");
    query.bindValue(":customer", customerName);
    query.exec();

    ordersModel->setQuery(query);
    ui->ordersTableView->setModel(ordersModel);
}

void CustomerDashboardWidget::on_createOrderButton_clicked() {
    showOrderForm();
}

void CustomerDashboardWidget::showOrderForm() {
    bool ok;
    QString type = QInputDialog::getText(this, "Create Order", "Type:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    QString start_point = QInputDialog::getText(this, "Create Order", "Start Point:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    QString end_point = QInputDialog::getText(this, "Create Order", "End Point:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    double mass = QInputDialog::getDouble(this, "Create Order", "Mass:", 0, 0, 10000, 2, &ok);
    if (!ok) return;

    double volume = QInputDialog::getDouble(this, "Create Order", "Volume:", 0, 0, 10000, 2, &ok);
    if (!ok) return;

    QSqlQuery query;
    query.prepare("INSERT INTO orders (customer, mass, volume, type, start_point, end_point) "
                  "VALUES (:customer, :mass, :volume, :type, :start_point, :end_point)");
    query.bindValue(":customer", customerName);
    query.bindValue(":mass", mass);
    query.bindValue(":volume", volume);
    query.bindValue(":type", type);
    query.bindValue(":start_point", start_point);
    query.bindValue(":end_point", end_point);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to create order: " + query.lastError().text());
    } else {
        loadOrders();
    }
}
