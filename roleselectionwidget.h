#ifndef ROLESELECTIONWIDGET_H
#define ROLESELECTIONWIDGET_H

#include <QWidget>

namespace Ui {
class RoleSelectionWidget;
}

class RoleSelectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RoleSelectionWidget(QWidget *parent = nullptr);
    ~RoleSelectionWidget();

signals:
    void roleSelected(const QString &role);

private slots:
    void on_customerButton_clicked();
    void on_providerButton_clicked();

private:
    Ui::RoleSelectionWidget *ui;
};

#endif // ROLESELECTIONWIDGET_H
