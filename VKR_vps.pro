QT += core gui widgets network sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VKR_vps
TEMPLATE = app

SOURCES += main.cpp \
           customer_dashboard_widget.cpp \
           mainwindow.cpp \
           loginwidget.cpp \
           registrationwidget.cpp \
           roleselectionwidget.cpp \
           server.cpp

HEADERS += mainwindow.h \
           customer_dashboard_widget.h \
           loginwidget.h \
           registrationwidget.h \
           roleselectionwidget.h \
           server.h

FORMS += mainwindow.ui \
         customer_dashboard_widget.ui \
         dostavka.ui \
         lk_provider.ui \
         lk_ts.ui \
         loginwidget.ui \
         registrationwidget.ui \
         roleselectionwidget.ui

# Убедитесь, что у вас установлены пути к библиотекам и инклюдам Qt
