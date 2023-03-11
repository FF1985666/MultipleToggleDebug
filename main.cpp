#include "mainwindow.h"

#include <QApplication>
#include "MultipleToggleDebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    dbg<<"loadData"<< "this line will not output";
    dbg<<"debugtoolboxcode"<< "this line will output";

    //MainWindow w;
    //w.show();
    return a.exec();
}
