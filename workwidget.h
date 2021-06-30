#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QWidget>
#include <world.h>
#include <widget.h>
#include <consolewidget.h>
#include <random>
#include <QDial>

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
    World *world;
    Widget *mainWidget;
    ConsoleWidget *textEdit;
    QTimer *timer;
    int radioLVL;

    WorkWidget(World *world);
    void ConsoleOut(const QString &text);
private:
    void randomWorkChannel();
    QVector<channel> workChannel;
    QVector<QDial*> *qDials;

public slots:
    void changeRadioValue(int value);
private slots:
    void textChanged();
};

#endif // WORKWIDGET_H
