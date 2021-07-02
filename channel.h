#ifndef CHANNEL_H
#define CHANNEL_H

#include <QWidget>
#include <workwidget.h>

class Channel : public QObject
{
    Q_OBJECT
public:
    WorkWidget *workWidget;
    Widget *mainWidget;
    Channel(Widget *mainWidget,WorkWidget *workWidget, int LVL);
    int LVL;
public slots:
    void makeGame();
};

#endif // CHANNEL_H
