#include "app.hpp"
#include <QBoxLayout>
#include <QLabel>

MainApp::MainApp() {
    stack = new QStackedWidget(this);
    setCentralWidget(stack);

    auto* main = new QWidget();
    stack->addWidget(main);
    auto mlay = new QVBoxLayout(main);
        {auto* labl = new QLabel("Main area", this);
        labl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        labl->setStyleSheet("background-color: red");
        mlay->addWidget(labl);}
        {auto* labl = new QLabel("Idea input", this);
        labl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        labl->setStyleSheet("background-color: blue");
        mlay->addWidget(labl);}

    setupStyle(true);
}
