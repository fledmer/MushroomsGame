#include "widget.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.SetPersoneImage();
    w.SetPersoneStat();
    return a.exec();
}
