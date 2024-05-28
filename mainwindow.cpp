#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stackedWidget(new QStackedWidget(this))
    , loginWidget(new LoginWidget(this))
    , roleSelectionWidget(new RoleSelectionWidget(this))
    , customerDashboardWidget(new CustomerDashboardWidget(this))
{
    ui->setupUi(this);

    // Добавляем виджеты в QStackedWidget
    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(roleSelectionWidget);
    stackedWidget->addWidget(customerDashboardWidget);

    setCentralWidget(stackedWidget);

    connect(loginWidget, &LoginWidget::loginSuccessful, this, &MainWindow::showRoleSelection);
    connect(roleSelectionWidget, &RoleSelectionWidget::roleSelected, this, &MainWindow::onRoleSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRoleSelection()
{
    stackedWidget->setCurrentWidget(roleSelectionWidget);
}

void MainWindow::onRoleSelected(const QString &role)
{
    if (role == "customer") {
        customerDashboardWidget->setCustomerName("customer_name"); // Используйте реальное имя заказчика
        stackedWidget->setCurrentWidget(customerDashboardWidget);
    } else if (role == "provider") {
        // Добавьте логику для провайдера
    }
}
