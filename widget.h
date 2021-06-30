#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <world.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    World *world;
    void SetPersoneImage();
    void SetPersoneStat();

    QGridLayout *mainLayout;

    QWidget *mainWidget;
    QLabel *personeDisplayWidget;
    QFrame *personeStatWidget;


    QLabel *healthStatLabel;
    QLabel *mindStatLabel;
    QLabel *moneyStatLabel;
    QLabel *stalkingStatLabel;
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void ChoiseWorkSlot();
};
#endif // WIDGET_H
