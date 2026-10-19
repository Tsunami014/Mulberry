#pragma once
#include <QMainWindow>
#include <QStackedWidget>

class MainApp : public QMainWindow {
    Q_OBJECT
public:
    MainApp();

private:
    QStackedWidget* stack;
};
