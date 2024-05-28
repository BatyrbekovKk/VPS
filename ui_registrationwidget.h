/********************************************************************************
** Form generated from reading UI file 'registrationwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWIDGET_H
#define UI_REGISTRATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
    QPushButton *registerButton;

    void setupUi(QWidget *RegistrationWidget)
    {
        if (RegistrationWidget->objectName().isEmpty())
            RegistrationWidget->setObjectName("RegistrationWidget");
        RegistrationWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegistrationWidget);
        verticalLayout->setObjectName("verticalLayout");
        usernameLineEdit = new QLineEdit(RegistrationWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(RegistrationWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        confirmPasswordLineEdit = new QLineEdit(RegistrationWidget);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(confirmPasswordLineEdit);

        registerButton = new QPushButton(RegistrationWidget);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);


        retranslateUi(RegistrationWidget);

        QMetaObject::connectSlotsByName(RegistrationWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWidget)
    {
        RegistrationWidget->setWindowTitle(QCoreApplication::translate("RegistrationWidget", "RegistrationWidget", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationWidget", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationWidget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        confirmPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("RegistrationWidget", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        registerButton->setText(QCoreApplication::translate("RegistrationWidget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWidget: public Ui_RegistrationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWIDGET_H
