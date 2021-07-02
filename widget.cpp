#include "widget.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <workwidget.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    world = new World();

    this->setStyleSheet("background:black;");
    this->resize(1500,800);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    mainLayout = new QGridLayout();
    mainLayout->setSpacing(0);
    {
        //Верхнее кнопочное пространство

        QHBoxLayout *layout = new QHBoxLayout();
        layout->setSpacing(0);
        QFont statButtonFont("Bahnschrift",1,1);
        statButtonFont.setPixelSize(25);
        QPushButton *worldButton = new QPushButton("Мир");
        worldButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        worldButton->setMinimumHeight(80);
        QPushButton *workButton = new QPushButton("Работа");
        workButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        workButton->setMinimumHeight(80);
        QPushButton *healthButton = new QPushButton("Здоровье");
        healthButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        healthButton->setMinimumHeight(80);
        QPushButton *restButton = new QPushButton("Отдых");
        restButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        restButton->setMinimumHeight(80);
        QPushButton *soulButton = new QPushButton("Разум");
        soulButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        soulButton->setMinimumHeight(80);
        QPushButton *personButton = new QPushButton("Вы");
        personButton->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
        personButton->setMinimumHeight(80);

        connect(workButton,SIGNAL(clicked()),SLOT(ChoiseWorkSlot()));

//        worldButton->setStyleSheet("color:#68da23;");
//        workButton->setStyleSheet("color:#68da23;");
//        healthButton->setStyleSheet("color:#68da23;");
//        restButton->setStyleSheet("color:#68da23;");
//        soulButton->setStyleSheet("color:#68da23;");
//        personButton->setStyleSheet("color:#68da23;");

        worldButton->setFont(statButtonFont);
        workButton->setFont(statButtonFont);
        healthButton->setFont(statButtonFont);
        restButton->setFont(statButtonFont);
        soulButton->setFont(statButtonFont);
        personButton->setFont(statButtonFont);

        layout->addWidget(worldButton);
        layout->addWidget(workButton);
        layout->addWidget(healthButton);
        layout->addWidget(restButton);
        layout->addWidget(soulButton);
        layout->addWidget(personButton);

        mainLayout->addLayout(layout,0,0,1,6);
    }

    {
        //Нижнее пространство
       {
        //Основной виджет
        mainWidget = new QWidget(this);
        mainWidget->setStyleSheet("background-color:black;");
        mainLayout->addWidget(mainWidget,1,0,8,5);
       }
       {
           //Виджет отображения персонажа
           QFrame *widget = new QFrame();
           //widget->setStyleSheet("background-color: black;border-style: solid;border-width:1px;border-color: white;");
           QHBoxLayout *bLayout = new QHBoxLayout();
           personeDisplayWidget = new QLabel();
           personeDisplayWidget->setStyleSheet("background-color: black;border-style: solid;border-width:1px;border-color: white;");
           bLayout->addWidget(personeDisplayWidget);
           widget->setLayout(bLayout);
           mainLayout->addWidget(personeDisplayWidget,1,5,5,1);
       }
       {
            //Минибокс с текстовой инофрмацией
            personeStatWidget = new QFrame(this);
            QFont statLabelFont("Bahnschrift",1,1);
            statLabelFont.setPixelSize(30);

            QFrame *bWidget = new QFrame();

            healthStatLabel = new QLabel();
            mindStatLabel = new QLabel();
            moneyStatLabel = new QLabel();
            stalkingStatLabel = new QLabel();

            healthStatLabel->setStyleSheet("border-style: solid;border-width:0px;color:#68da23;");
            mindStatLabel->setStyleSheet("border-style: solid;border-width:0px;color:#68da23;");
            moneyStatLabel->setStyleSheet("border-style: solid;border-width:0px;color:#68da23;");
            stalkingStatLabel->setStyleSheet("border-style: solid;border-width:0px;color:#68da23;");

            healthStatLabel->setFont(statLabelFont);
            mindStatLabel->setFont(statLabelFont);
            moneyStatLabel->setFont(statLabelFont);
            stalkingStatLabel->setFont(statLabelFont);

            QVBoxLayout *vLayout = new QVBoxLayout();
            vLayout->setSpacing(9);
            vLayout->addWidget(healthStatLabel);
            vLayout->addWidget(mindStatLabel);
            vLayout->addWidget(moneyStatLabel);
            vLayout->addWidget(stalkingStatLabel);
            personeStatWidget->setLayout(vLayout);
            personeStatWidget->setStyleSheet("background-color: black;border-style: solid;border-width:1px;border-color: white;");
            mainLayout->addWidget(personeStatWidget,6,5,3,1);
       }
    }

    this->setLayout(mainLayout);

}

void Widget::SetPersoneImage()
{
    QPixmap pic(world->mainCharacter->current_face);
    pic = pic.scaled(personeDisplayWidget->size(),Qt::IgnoreAspectRatio);
    personeDisplayWidget->setPixmap(pic);
}

void Widget::SetPersoneStat()
{
    healthStatLabel->setText(" Здоровье: " + QString::number(world->mainCharacter->health));
    mindStatLabel->setText(" Рассудок: " + QString::number(world->mainCharacter->mind));
    moneyStatLabel->setText(" Деньги: " + QString::number(world->mainCharacter->money) + " ₽");
    stalkingStatLabel->setText(" Сталкинг: " + QString::number(world->mainCharacter->stalkingLVL));
}

void Widget::ChoiseWorkSlot()
{
    delete mainWidget;
    mainWidget = new WorkWidget(this);
    mainWidget->setStyleSheet("background: black");
    mainLayout->addWidget(mainWidget,1,0,8,5);
}

Widget::~Widget()
{
}

