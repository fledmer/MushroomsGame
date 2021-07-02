#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QWidget>
#include <world.h>
#include <widget.h>
#include <consolewidget.h>
#include <random>
#include <QDial>
#include <QPushButton>

struct channel{
    int id;
    int lvl;
    channel(int id, int lvl){
        this->id = id;this->lvl = lvl;
    }
};

class WorkWidget: public QWidget
{
    Q_OBJECT
public:
    WorkWidget(Widget *mainWidget);
    Widget *mainWidget;
    World *world;
    ConsoleWidget *textEdit;
    QTimer *timer;
    QPushButton *connectButton;
    int channelLVL;

    void MuteAllWidgets();
    void unMuteAllWidgets();
private:
    void randomChannels();
    QVector<channel> workChannel;
    QVector<QDial*> *qDials;


public slots:
    void changeRadioValue(int value);
private slots:
    void textChanged();
    void createChannel();

};

#endif // WORKWIDGET_H
