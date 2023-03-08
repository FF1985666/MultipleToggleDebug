#include "mainwindow.h"

#include <QApplication>
#include "MultipleToggleDebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    debugtoggle<<"1"<< "this line will output";
    debugtoggle<<"6"<< "this line will not output";

    //MainWindow w;
    //w.show();
    return a.exec();
}
