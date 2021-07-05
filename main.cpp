#include "widget.h"

#include <QApplication>
#include <QFontDatabase>
#include <hellowindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    //w.SetPersoneImage();
    //w.SetPersoneStat();

    HelloWindow h;
    h.show();
    return a.exec();
}
