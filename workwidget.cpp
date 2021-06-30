#include "workwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDial>
#include <QGridLayout>
#include <QTextEdit>
#include <QSlider>
#include <random>
#include <QString>
#include <time.h>
#include <QScrollBar>
#include <QTimer>

WorkWidget::WorkWidget(World *world):world(world),workChannel()
{
    QGridLayout *mainLayout = new QGridLayout;
    QFont statLabelFont("System",1,1);
    this->setStyleSheet("background-color: black");
    statLabelFont.setPixelSize(15);
    //Создание виджетов

    {
        //Надпись

        {
            QLabel *label = new QLabel(" ИНФОРМАЦИОННЫЙ АППАРАТ: \n ВАСИЛИЙ \n ВИДИТ \n ВСЕ");
            label->setFont(QFont("System",20,20));
            label->setStyleSheet("color: #7bd7c2");
            mainLayout->addWidget(label,0,0,1,1);}

        //Консольное окно

        {
            textEdit = new ConsoleWidget();
            connect(textEdit,SIGNAL(textChanged()),SLOT(textChanged()));
            mainLayout->addWidget(textEdit,0,1,2,5);
            textEdit->PrintText("Загрузка....\n");
            textEdit->PrintText("Добро пожаловать в систему",1);}

        //Кнопка ПОИСКА

        {
            QPushButton *button = new QPushButton();
            button->setStyleSheet("background-color: black;color: #68da23;\
            border-style: solid;border-width:1px;border-color: white;");
            button->setText("ВОЙТИ");
            button->setMinimumSize(200,120);
            button->setFont(QFont("System",20,20));
            //button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            mainLayout->addWidget(button,2,3,1,1);}

        //Ползунки

        {
            QStringList a;
            a << "D" << "C\n VFO" << "CS" << "AUX\n C" << "COU" << "FQ";
            qDials = new QVector<QDial*>;

            for(int x = 0; x < 6; x++){
                QVBoxLayout *Layout1 = new QVBoxLayout();
                QDial *Dial1 = new QDial();
                Dial1->setRange(0,10);
                Dial1->setNotchTarget(10);
                Dial1->setNotchesVisible(true);
                Dial1->setStyleSheet("background-color: green;");
                connect(Dial1,SIGNAL(valueChanged(int)),SLOT(changeRadioValue(int)));
                QLabel *Label1 = new QLabel(a[x]);
                Label1->setStyleSheet("color: #68da23");
                Label1->setFont(statLabelFont);
                Label1->setBuddy(Dial1);
                Label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                Layout1->addWidget(Dial1);
                Layout1->addWidget(Label1);
                qDials->push_back(Dial1);
                mainLayout->addLayout(Layout1,2,x+x/3);
            }
        }

    }

    randomWorkChannel();
    setLayout(mainLayout);
    timer = new QTimer(this);
    timer->setInterval(100);
}

void WorkWidget::randomWorkChannel()
{
    workChannel.clear();
    srand(time(0));
    radioLVL = 0;
    for(int x = 0; x < 1000;x++){
       workChannel.push_back(channel(rand()%1000000,1));
    }
    for(int x = 0; x < 100+world->mainCharacter->stalkingLVL;x++){
        workChannel.push_back(channel(rand()%1000000,2));
    }
    for(int x = 0; x < world->mainCharacter->stalkingLVL;x++){
        workChannel.push_back(channel(rand()%1000000,3));
    }

    //for(int x = 0; x < workChannel.size(); x++){
    //    qDebug() << (workChannel[x].id);
    //}
    //textEdit->insertPlainText(">:Вход в систему выполнен\n>:Выберите нужную волну, а после нажмите ПОИСК\n");
}

void WorkWidget::changeRadioValue(int value)
{
    radioLVL = 0;
    int sum = 0;
    for(int x = 0; x < 6; x++){
        sum += (*qDials)[x]->value()*pow(10,x);
    }
    for(int x = 0; x < workChannel.size();x++){
        if(workChannel[x].id==sum){
            textEdit->PrintText("Найден канал " + QString::number(workChannel[x].lvl)
                                      + " уровня!\n");
            qDebug() << workChannel[x].id;
            radioLVL = workChannel[x].lvl;
            break;
        }
    }

    if(radioLVL == 0){
        textEdit->PrintText("пщппщпщщ...\n");
    }

}

void WorkWidget::textChanged()
{
    QScrollBar *x = textEdit->verticalScrollBar();
    x->setValue(x->maximum());
}

