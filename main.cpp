#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QCoreApplication::setApplicationName("Mulberry");
    QApplication app(argc, argv);

    QLabel label("Hello, World!");
    label.setWindowTitle("My First Qt App");
    label.resize(300, 100);
    label.setAlignment(Qt::AlignCenter);

    label.show();
    return app.exec();
}
