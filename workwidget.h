#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QWidget>
#include <world.h>
#include <widget.h>

class WorkWidget: public QWidget
{
    Q_OBJECT
public:
    World *world;
    Widget *mainWidget;

    WorkWidget();
};

#endif // WORKWIDGET_H
