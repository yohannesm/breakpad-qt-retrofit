#include <QApplication>
#include <QTextEdit>
#include <QString>
#include "qt-breakpad/qt_breakpad.h"
#include <iostream>

int buggyFunc(){
    delete reinterpret_cast<QString*>(0xFEE1DEAD);
    return 0;
}

int main(int argv, char** args)
{
    QString reportPath = QDir::current().absolutePath();
    QtBreakpad::init(reportPath);

    QApplication app(argv, args);
    buggyFunc();

    QTextEdit textEdit;
    textEdit.show();

    return app.exec();
}

