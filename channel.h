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
    void succesHack();
    Channel(Widget *mainWidget,WorkWidget *workWidget, int channelLvl);
private:
    QStringList dialogs;
    QStringList messages;
    World *world;
    MainCharacter *player;
    QVector<int> channelFilling;
    int channelLvl;
    int state;
    int fileCount;
    bool isFind;
    int inChannelPosition;
    void finding();
signals:
    void nextMessage();
public slots:
    void messageEnd1();
    void messageEnd2();
    void messageEnd2a1();
    void choiseWidgetSlot(bool value);
};

#endif // CHANNEL_H
