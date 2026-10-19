#include <QApplication>
#include "app.hpp"

MainApp* MA = nullptr;

int main(int argc, char* argv[]) {
    QCoreApplication::setApplicationName("Mulberry");
    QApplication app(argc, argv);

    QFont font = QApplication::font();
    font.setPointSize(16);
    QApplication::setFont(font);

    MA = new MainApp();
    MA->setWindowFlags(MA->windowFlags() | Qt::ExpandedClientAreaHint);
    MA->show();
    return app.exec();
}
