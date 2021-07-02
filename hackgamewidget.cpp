#include "hackgamewidget.h"
#include <random>
#include <time.h>
#include <QtCore>
#include <QKeyEvent>
#include <QGridLayout>

CandyWorld::CandyWorld(int w_count, int h_count):candyEatCount(0)
{
    srand(time(0));
    this->w_count = w_count*2+1;
    this->h_count = h_count*2+1;
    playerPosition = new QPoint(1,1);
    candyPosition = new QPoint(1,0);
    world = GenerateMaze(h_count,w_count);
    for(int x = 0; x < h_count; x++)
        world->push_back(QVector<int>(w_count));
    (*world)[1][1] = 1; //Player
    while(*playerPosition == *candyPosition ||
          (*world)[candyPosition->y()][candyPosition->x()] == -1)
    {
        candyPosition->setX(rand()%w_count);
        candyPosition->setY(rand()%h_count);
    }
    (*world)[candyPosition->y()][candyPosition->x()] = 2;
}

void CandyWorld::Update(int direction)
{
    auto candyEat = false;
    auto oldPlayerPosition = *playerPosition;
    (*world)[playerPosition->y()][playerPosition->x()] = 0;
    (*world)[candyPosition->y()][candyPosition->x()] = 0;
    if(direction == 0)
        playerPosition->setX(playerPosition->x()-1);
    else if(direction == 1)
        playerPosition->setX(playerPosition->x()+1);
    else if(direction == 2)
        playerPosition->setY(playerPosition->y()-1);
    else if(direction == 3)
        playerPosition->setY(playerPosition->y()+1);

    if((*world)[playerPosition->y()][playerPosition->x()] == -1){
        *playerPosition = oldPlayerPosition;
        qDebug() << "WALL";
    }

    while(*playerPosition == *candyPosition ||
          (*world)[candyPosition->y()][candyPosition->x()] == -1)
    {
        candyPosition->setX(rand()%w_count);
        candyPosition->setY(rand()%h_count);
        candyEat = true;
    }
    if(candyEat)candyEatCount++;
    (*world)[playerPosition->y()][playerPosition->x()] = 1;
    (*world)[candyPosition->y()][candyPosition->x()] = 2;
}

QVector<QVector<int>>* CandyWorld::GenerateMaze(int height, int width)
{
    {
        int output_height = height*2+1;
        int output_width = width*2+1;
        auto maze = new QVector<QVector<int>>();
        for (int i = 0; i < output_height; ++i)
        {
            QVector<int> row;
            row.reserve(output_width);
            for (int j = 0; j < output_width; ++j)
                if ((i % 2 == 1) && (j % 2 == 1))
                    row.push_back(0);
                else
                    if (((i % 2 == 1) && (j % 2 == 0) && (j != 0) && (j != output_width - 1)) ||
                        ((j % 2 == 1) && (i % 2 == 0) && (i != 0) && (i != output_height - 1)))
                        row.push_back(0);
                    else
                        row.push_back(-1);
            maze->push_back(std::move(row));
        }
        QVector<int> row_set;
        for (int i = 0; i < width; ++i)
            row_set.push_back(0);
        unsigned set = 1;
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 2);
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
                if (row_set[j] == 0)
                    row_set[j] = set++;
            for (int j = 0; j < width - 1; ++j)
            {
                const auto right_wall = dist(mt);
                if ((right_wall == 1) || (row_set[j] == row_set[j + 1]))
                    (*maze)[i * 2 + 1][j * 2 + 2] = -1;
                else
                {
                    const auto changing_set = row_set[j + 1];
                    for (int l = 0; l < width; ++l)
                        if (row_set[l] == changing_set)
                            row_set[l] = row_set[j];
                }
            }

            for (int j = 0; j < width; ++j)
            {
                const auto bottom_wall = dist(mt);
                unsigned int count_current_set = 0;
                for (int l = 0; l < width; ++l)
                    if (row_set[j] == row_set[l])
                        count_current_set++;
                if ((bottom_wall == 1) && (count_current_set != 1))
                    (*maze)[i * 2 + 2][j * 2 + 1] = -1;
            }
            if (i != height - 1)
            {
                for (int j = 0; j < width; ++j) {
                    int count_hole = 0;
                    for (int l = 0; l < width; ++l)
                        if ((row_set[l] == row_set[j]) && (*maze)[i * 2 + 2][l * 2 + 1] == 0)
                            count_hole++;
                    if (count_hole == 0)
                        (*maze)[i * 2 + 2][j * 2 + 1] = 0;
                }
                for (int j = 0; j < width; ++j)
                    if ((*maze)[i * 2 + 2][j * 2 + 1] == -1)
                        row_set[j] = 0;
            }
        }
        for (int j = 0; j < width - 1; ++j)
        {
            if (row_set[j] != row_set[j + 1])
                (*maze)[output_height - 2][j * 2 + 2] = 0;
        }
        return maze;
    }
}

CandyWorld::~CandyWorld()
{
    delete world;
    delete playerPosition;
    delete candyPosition;
}


HackGameWidget::HackGameWidget(QWidget *parent)
{
    w_size = 3;h_size =3;candyLvl=0;
    StartGame();
    Update();
}

HackGameWidget::~HackGameWidget()
{
}

void HackGameWidget::StartGame()
{
    if(candyLvl != 0){
    delete candyEatLabel;
    delete candyLvlLabel;
    delete candyWorld;
    delete graphicsMatrix;
    }

    QGridLayout *mainLayout = new QGridLayout();
    candyWorld = new CandyWorld(w_size,h_size);
    worldMatrix = candyWorld->world;
    int _w_size = w_size*2+1;
    int _h_size = h_size*2+1;
    //такие размеры нужны для работы с матрицей
    graphicsMatrix = new QVector<QVector<QWidget*>>();

    for(int y = 0; y < _h_size; y++){
        graphicsMatrix->push_back(QVector<QWidget*>());
        for(int x = 0; x < _w_size; x++){
            ((*graphicsMatrix)[y]).push_back(new QWidget(this));
            mainLayout->addWidget((*graphicsMatrix)[y][x],y,x,1,1);
            ((*graphicsMatrix)[y])[x]->show();
        }
    }

//    candyLvlLabel = new QLabel(this);
//    candyLvlLabel->setFont(QFont("Caveat",20,20,true));
//    candyLvlLabel->setGeometry(820,15,400,100);
//    candyLvlLabel->setText("Уровень: " + QString::number(candyLvl));
//    candyLvlLabel->show();
//    candyEatLabel = new QLabel(this);
//    candyEatLabel->setFont(QFont("Caveat",20,20,true));
//    candyEatLabel->setGeometry(820,60,400,100);
//    candyEatLabel->show();

    this->setLayout(mainLayout);

    Update();
}

void HackGameWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        candyWorld->Update(0);
    else if(event->key() == Qt::Key_Right)
        candyWorld->Update(1);
    else if(event->key() == Qt::Key_Up)
        candyWorld->Update(2);
    else if(event->key() == Qt::Key_Down)
        candyWorld->Update(3);
    Update();
}

void HackGameWidget::Update()
{
    for(int y = 0; y < h_size*2+1; y++)
    {
        for(int x = 0; x < w_size*2+1; x++)
        {
            if((*worldMatrix)[y][x] == 1)
            {
                ((*graphicsMatrix)[y])[x]->setStyleSheet("background-color: white;");
                ((*graphicsMatrix)[y])[x]->setAutoFillBackground(true);
                ((*graphicsMatrix)[y])[x]->show();
            }
            else if((*worldMatrix)[y][x] == 2)
            {
                ((*graphicsMatrix)[y])[x]->setStyleSheet("background-color: yellow;");
                ((*graphicsMatrix)[y])[x]->setAutoFillBackground(true);
                ((*graphicsMatrix)[y])[x]->show();
            }
            else if((*worldMatrix)[y][x] == -1)
            {
                ((*graphicsMatrix)[y])[x]->setStyleSheet("background-color: green;");
                ((*graphicsMatrix)[y])[x]->setAutoFillBackground(true);
                ((*graphicsMatrix)[y])[x]->show();
            }
            else
            {
                ((*graphicsMatrix)[y])[x]->setStyleSheet("background-color: black;");
                ((*graphicsMatrix)[y])[x]->setAutoFillBackground(true);
                ((*graphicsMatrix)[y])[x]->show();
            }
        }
    }

    //candyEatLabel->setText("Свинья съела "
    //+ QString::number(candyWorld->candyEatCount)
    //+ " конфет");

    if(candyWorld->candyEatCount == 5)
    {
        candyLvl++;w_size+=2;h_size+=2;
        StartGame();
    }
}
