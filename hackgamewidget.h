 #ifndef HACKGAMEWIDGET_H
#define HACKGAMEWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QLabel>
#include <channel.h>

class CandyWorld
{
public:
    QVector<QVector<int>> *world;
    int candyEatCount;
    CandyWorld(int w_count, int h_count);
    ~CandyWorld();
    void Update(int direction);
private:
    QVector<QVector<int>>* GenerateMaze(int height,int width);
    int h_count,w_count;
    void Roll();
    QPoint *playerPosition;
    QPoint *candyPosition;
};

class HackGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HackGameWidget(int mazeSize, int candyCount);
    ~HackGameWidget();
    Channel *parentChannel;
    int mazeSize;
    int candyLvl;
    int candyCount;
    void StartGame();
    void Update();
    void keyPressEvent(QKeyEvent *event);
private:
    WorkWidget *mainWidget;
    CandyWorld *candyWorld;
    QVector<QVector<int>> *worldMatrix;
    QVector<QVector<QWidget*>> *graphicsMatrix;

public slots:
    void keyPressSlot(QKeyEvent*);
};

#endif // HACKGAMEWIDGET_H
