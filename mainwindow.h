#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "loginwidget.h"
#include "roleselectionwidget.h"
#include "customer_dashboard_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRoleSelection();
    void onRoleSelected(const QString &role);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    LoginWidget *loginWidget;
    RoleSelectionWidget *roleSelectionWidget;
    CustomerDashboardWidget *customerDashboardWidget;
};

#endif // MAINWINDOW_H
