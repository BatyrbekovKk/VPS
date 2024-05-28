#include "roleselectionwidget.h"
#include "ui_roleselectionwidget.h"

RoleSelectionWidget::RoleSelectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoleSelectionWidget)
{
    ui->setupUi(this);
}

RoleSelectionWidget::~RoleSelectionWidget()
{
    delete ui;
}

void RoleSelectionWidget::on_customerButton_clicked()
{
    emit roleSelected("customer");
}

void RoleSelectionWidget::on_providerButton_clicked()
{
    emit roleSelected("provider");
}
