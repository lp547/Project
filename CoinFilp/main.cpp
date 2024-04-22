#include "mymainwindow.h"
#include <QApplication>
#include "startscene.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyMainWindow w;
//    w.show();
    StartScene sc;
    sc.show();
    return a.exec();
}
