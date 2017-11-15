#include "mainwindow.h"
#include <QApplication>
#include "modeltest.h"

//void runTests()
//{
//    ModelTests tests;
//    QTest::qExec(&tests);
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
