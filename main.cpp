#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    MainWindow main;
    w.connect(&w, SIGNAL(loginSuccess()), &main, SLOT(show()));
    w.show();

    return a.exec();
}
