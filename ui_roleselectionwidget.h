/********************************************************************************
** Form generated from reading UI file 'roleselectionwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLESELECTIONWIDGET_H
#define UI_ROLESELECTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleSelectionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *customerButton;
    QPushButton *providerButton;

    void setupUi(QWidget *RoleSelectionWidget)
    {
        if (RoleSelectionWidget->objectName().isEmpty())
            RoleSelectionWidget->setObjectName("RoleSelectionWidget");
        RoleSelectionWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(RoleSelectionWidget);
        verticalLayout->setObjectName("verticalLayout");
        customerButton = new QPushButton(RoleSelectionWidget);
        customerButton->setObjectName("customerButton");

        verticalLayout->addWidget(customerButton);

        providerButton = new QPushButton(RoleSelectionWidget);
        providerButton->setObjectName("providerButton");

        verticalLayout->addWidget(providerButton);


        retranslateUi(RoleSelectionWidget);

        QMetaObject::connectSlotsByName(RoleSelectionWidget);
    } // setupUi

    void retranslateUi(QWidget *RoleSelectionWidget)
    {
        RoleSelectionWidget->setWindowTitle(QCoreApplication::translate("RoleSelectionWidget", "Select Role", nullptr));
        customerButton->setText(QCoreApplication::translate("RoleSelectionWidget", "Customer", nullptr));
        providerButton->setText(QCoreApplication::translate("RoleSelectionWidget", "Provider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoleSelectionWidget: public Ui_RoleSelectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLESELECTIONWIDGET_H
