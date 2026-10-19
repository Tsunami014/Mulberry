#include "app.hpp"
#include <QFile>
#ifdef Q_OS_ANDROID
#include <QTimer>
#include <QJniObject>
#include <QCoreApplication>
#include <QtCore/qnativeinterface.h>
#endif

void MainApp::setupStyle(bool init) {
    const bool light = true; // For dark mode, the stylesheets will need to change

    static QString mstyl = [](){
        QFile file(":/style.qss");
        bool ok = file.open(QIODevice::ReadOnly);
        // Should always be ok because we're loading from a preset internal file
        return QString::fromUtf8(file.readAll());
    } ();
    setStyleSheet(mstyl);

    // If on Android, set the navigation icons to be dark/light with the theme
#ifdef Q_OS_ANDROID
    auto updFn = [this, light]() {
        QNativeInterface::QAndroidApplication::runOnAndroidMainThread([light]() {
            QJniObject activity = QNativeInterface::QAndroidApplication::context();
            QJniObject window = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");

            if (QNativeInterface::QAndroidApplication::sdkVersion() >= 30) {
                QJniObject controller = window.callObjectMethod(
                    "getInsetsController", "()Landroid/view/WindowInsetsController;");
                if (controller.isValid()) {
                    const int APPEARANCE_LIGHT_STATUS_BARS = 8;
                    const int APPEARANCE_LIGHT_NAVIGATION_BARS = 16;
                    int mask = APPEARANCE_LIGHT_STATUS_BARS | APPEARANCE_LIGHT_NAVIGATION_BARS;
                    int value = light ? mask : 0;   // set flag => dark icons on light bg
                    controller.callMethod<void>("setSystemBarsAppearance", "(II)V", value, mask);
                }
            } else {
                QJniObject decorView = window.callObjectMethod("getDecorView", "()Landroid/view/View;");
                jint visibility = decorView.callMethod<jint>("getSystemUiVisibility", "()I");

                const int flags = 0x2000 | 0x10; // LIGHT_STATUS_BAR | LIGHT_NAVIGATION_BAR
                visibility = light ? (visibility | flags) : (visibility & ~flags);

                decorView.callMethod<void>("setSystemUiVisibility", "(I)V", visibility);
            }
        });
    };

    if (init) {
        QTimer::singleShot(0, updFn);
    } else { updFn(); }
#endif

    if (!init) emit themeChange();
}
