#pragma once
#include <QMainWindow>
#include <QStackedWidget>

class MainApp : public QMainWindow {
    Q_OBJECT
public:
    MainApp();

    void setupStyle();

signals:
    void themeChange();

private:
    QStackedWidget* stack;

    void setupStyle(bool init = false);
};
