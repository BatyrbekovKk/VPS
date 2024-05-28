#ifndef CUSTOMERDASHBOARDWIDGET_H
#define CUSTOMERDASHBOARDWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class CustomerDashboardWidget;
}

class CustomerDashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerDashboardWidget(QWidget *parent = nullptr);
    ~CustomerDashboardWidget();

    void setCustomerName(const QString &name);
    void loadOrders();

private slots:
    void on_createOrderButton_clicked();

private:
    Ui::CustomerDashboardWidget *ui;
    QString customerName;
    QSqlDatabase db;
    QSqlQueryModel *ordersModel;

    void initDatabase();
    void showOrderForm();
};

#endif // CUSTOMERDASHBOARDWIDGET_H
