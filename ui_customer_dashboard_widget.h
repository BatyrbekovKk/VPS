/********************************************************************************
** Form generated from reading UI file 'customer_dashboard_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_DASHBOARD_WIDGET_H
#define UI_CUSTOMER_DASHBOARD_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerDashboardWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *customerNameLabel;
    QTableView *ordersTableView;
    QPushButton *createOrderButton;

    void setupUi(QWidget *CustomerDashboardWidget)
    {
        if (CustomerDashboardWidget->objectName().isEmpty())
            CustomerDashboardWidget->setObjectName("CustomerDashboardWidget");
        CustomerDashboardWidget->resize(600, 400);
        verticalLayout = new QVBoxLayout(CustomerDashboardWidget);
        verticalLayout->setObjectName("verticalLayout");
        customerNameLabel = new QLabel(CustomerDashboardWidget);
        customerNameLabel->setObjectName("customerNameLabel");

        verticalLayout->addWidget(customerNameLabel);

        ordersTableView = new QTableView(CustomerDashboardWidget);
        ordersTableView->setObjectName("ordersTableView");

        verticalLayout->addWidget(ordersTableView);

        createOrderButton = new QPushButton(CustomerDashboardWidget);
        createOrderButton->setObjectName("createOrderButton");

        verticalLayout->addWidget(createOrderButton);


        retranslateUi(CustomerDashboardWidget);

        QMetaObject::connectSlotsByName(CustomerDashboardWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomerDashboardWidget)
    {
        CustomerDashboardWidget->setWindowTitle(QCoreApplication::translate("CustomerDashboardWidget", "Customer Dashboard", nullptr));
        customerNameLabel->setText(QCoreApplication::translate("CustomerDashboardWidget", "Welcome, [Customer]", nullptr));
        createOrderButton->setText(QCoreApplication::translate("CustomerDashboardWidget", "Create New Order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDashboardWidget: public Ui_CustomerDashboardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_DASHBOARD_WIDGET_H
