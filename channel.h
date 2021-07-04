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
    Channel(Widget *mainWidget,WorkWidget *workWidget, int channelLvl);
private:
    QStringList dialogs;
    World *world;
    MainCharacter *player;
    QVector<int> channelFilling;
    int channelLvl;
    int state;
    int fileCount;
    bool isFind;
    void succesHack();

    int inChannelPosition;
    void finding();
signals:
    void nextMessage();
public slots:
    void messageEnd1();
    void messageEnd2();
    void choiseWidgetSlot(bool value);
};

#endif // CHANNEL_H
