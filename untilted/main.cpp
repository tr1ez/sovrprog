#include <QApplication>
#include "calculator.h"
#include "logwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    LogWindow logwindow;
    Calculator calculator;
    logwindow.show();
    QObject::connect(&logwindow, &LogWindow::login_attempt_succeded, [&] {calculator.show();});
    //calculator.show();
    return app.exec();
}
