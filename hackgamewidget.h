 #ifndef HACKGAMEWIDGET_H
#define HACKGAMEWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QLabel>

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
    explicit HackGameWidget(QWidget *parent = nullptr);
    ~HackGameWidget();
    int w_size,h_size;
    int candyLvl;

private:
    void StartGame();
    void Update();
    //QWidget *curent;
    QLabel *candyLvlLabel;
    QLabel *candyEatLabel;
    CandyWorld *candyWorld;
    QVector<QVector<int>> *worldMatrix;
    QVector<QVector<QWidget*>> *graphicsMatrix;

    void keyPressEvent(QKeyEvent *event);
};

#endif // HACKGAMEWIDGET_H
