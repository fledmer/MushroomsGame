#include "workwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDial>
#include <QGridLayout>
#include <QTextEdit>
#include <QSlider>

WorkWidget::WorkWidget()
{
    QGridLayout *mainLayout = new QGridLayout;
    QFont statLabelFont("System",1,1);
    this->setStyleSheet("background-color: black");
    statLabelFont.setPixelSize(15);
    {
        {
            QLabel *label = new QLabel(" ИНФОРМАЦИОННОЕ УСТРОЙСТВО: \n ВАСИЛИЙ \n ВИДИТ \n ВСЕ");
            label->setFont(QFont("System",20,20));
            //label->setStyleSheet("color: #7bd7c2");
            mainLayout->addWidget(label,0,0,1,1);
        }

        {
            QTextEdit *textEdit = new QTextEdit();
            textEdit->setStyleSheet("background-color: black;border-width:5px;border-color: green;color: green;font-size:30 px;font:System");
            textEdit->zoomIn(20);
            mainLayout->addWidget(textEdit,0,1,2,5);
        }

        {
            QPushButton *button = new QPushButton();

            button->setStyleSheet("background-color: #000000;color: #68da23;border-width:2px;\
            border-color: #FFFFFF;");
            button->setText("ПОИСК");
            button->setFont(QFont("System",20,20));
            //button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            mainLayout->addWidget(button,2,3,1,1);
        }
        {
            QVBoxLayout *Layout1 = new QVBoxLayout();
            QDial *Dial1 = new QDial();
            Dial1->setRange(0,15);
            Dial1->setNotchTarget(15);
            Dial1->setNotchesVisible(true);
            Dial1->setStyleSheet("background-color: #25547B;");
            QLabel *Label1 = new QLabel("DRIVE");
            //Label1->setStyleSheet("color: #62AA2A;");
            Label1->setFont(statLabelFont);
            Label1->setBuddy(Dial1);
            Label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout1->addWidget(Dial1);
            Layout1->addWidget(Label1);

            QVBoxLayout *Layout2 = new QVBoxLayout();
            QDial *Dial2 = new QDial();
            Dial2->setRange(0,4);
            Dial2->setNotchTarget(4);
            Dial2->setNotchesVisible(true);
            Dial2->setStyleSheet("background-color: #25547B;");
            QLabel *Label2 = new QLabel("CRYSTALS\nVFO");
            //Label2->setStyleSheet("color: #62AA2A");
            Label2->setFont(statLabelFont);
            Label2->setBuddy(Dial2);
            Label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout2->addWidget(Dial2);
            Layout2->addWidget(Label2);

            QVBoxLayout *Layout3 = new QVBoxLayout();
            QDial *Dial3 = new QDial();
            Dial3->setRange(0,1000);
            //Dial1->setNotchTarget(10);
            //Dial1->setNotchesVisible(true);
            Dial3->setStyleSheet("background-color: #25547B;");
            QLabel *Label3 = new QLabel("CRYSTALS");
            //Label3->setStyleSheet("color: #62AA2A");
            Label3->setFont(statLabelFont);
            Label3->setBuddy(Dial3);
            Label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout3->addWidget(Dial3);
            Layout3->addWidget(Label3);

            QVBoxLayout *Layout4 = new QVBoxLayout();
            QDial *Dial4 = new QDial();
            Dial4->setRange(0,7);
            Dial4->setNotchTarget(7);
            Dial4->setNotchesVisible(true);
            Dial4->setStyleSheet("background-color: #25547B;");
            QLabel *Label4 = new QLabel("AUXILIARY\nCOUPLING");
            //Label4->setStyleSheet("color: #62AA2A");
            Label4->setFont(statLabelFont);
            Label4->setBuddy(Dial4);
            Label4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout4->addWidget(Dial4);
            Layout4->addWidget(Label4);

            QVBoxLayout *Layout5 = new QVBoxLayout();
            QDial *Dial5 = new QDial();
            Dial5->setRange(0,100);
            Dial5->setNotchTarget(10);
            Dial5->setNotchesVisible(true);
            Dial5->setStyleSheet("background-color: #25547B;");
            QLabel *Label5 = new QLabel("COUPLING");
            //Label5->setStyleSheet("color: #62AA2A");
            Label5->setFont(statLabelFont);
            Label5->setBuddy(Dial5);
            Label5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout5->addWidget(Dial5);
            Layout5->addWidget(Label5);

            QVBoxLayout *Layout6 = new QVBoxLayout();
            QDial *Dial6 = new QDial();
            Dial6->setRange(0,1000);
            Dial6->setNotchTarget(1000);
            Dial6->setNotchesVisible(true);
            Dial6->setStyleSheet("background-color: #25547B;");
            QLabel *Label6 = new QLabel("FREQUENCY");
            //Label6->setStyleSheet("color: #62AA2A");
            Label6->setFont(statLabelFont);
            Label6->setBuddy(Dial6);
            Label6->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Layout6->addWidget(Dial6);
            Layout6->addWidget(Label6);


            mainLayout->addLayout(Layout1,2,0);
            mainLayout->addLayout(Layout2,2,1);
            mainLayout->addLayout(Layout3,2,2);
            mainLayout->addLayout(Layout4,2,4);
            mainLayout->addLayout(Layout5,2,5);
            mainLayout->addLayout(Layout6,2,6);
        }

    }

    if(true)
    {
    }
    else if(world->mainCharacter->stalkingLVL > 10)
    {

    }
    else if(world->mainCharacter->stalkingLVL > 100)
    {

    }

    setLayout(mainLayout);
}
