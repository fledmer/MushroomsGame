    #include "hellowindow.h"
#include<QLabel>
#include<consolewidget.h>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<widget.h>
#include<QString>

HelloWindow::HelloWindow():QWidget()
{
    this->resize(650,900);
    this->setStyleSheet("background-color: black");
    QFont statLabelFont("Bahnschrift");
    statLabelFont.setPixelSize(30);
    button = new QPushButton();
    button->setMinimumHeight(80);
    button->setText("НАЧАТЬ");
    button->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;");
    button->setDisabled(true);
    button->setFont(statLabelFont);
    ConsoleWidget *label = new ConsoleWidget();
    label->setStyleSheet("border-style:solid;\
    border-width: 0px;background: black; color: green");
    label->SetFontSize(30);
    connect(label,SIGNAL(emptyStack()),this,SLOT(MessageEnd()));
    connect(button,SIGNAL(clicked()),this,SLOT(ButtonSlot()));
    label->PrintText("Каждую ночь сниться сон....\n",120);
    label->PrintText("В нем один призыв и этот код\n",140);
    label->PrintText("CS-6 C-3 D-1\n",200);
    label->PrintText("Он говорит, он... \n",140);
    label->PrintText("ВЕРНЕЕ МЫ\n",80);
    label->PrintText("желаем знать...\n",140);
    label->PrintText("Кажется что сходишь с ума\n",140);
    label->PrintText("Но больше не могу, я должен\n",80);
    label->PrintText("узнать что скрывает\n",60);
    label->PrintText("родной\n",240);
    label->PrintText("Г И Г А Х Р У Щ\n",340);
    label->PrintText("\n",500);
    label->PrintText("\n",500);
    label->PrintText("\n",500);
    label->PrintText("Программист: Михалев Никита\n",100);
    QVBoxLayout *vbl = new QVBoxLayout();
    vbl->addWidget(label);
    vbl->addWidget(button);
    QHBoxLayout *hbl = new QHBoxLayout();
    hbl->addLayout(vbl);
    setLayout(hbl);
}

void HelloWindow::MessageEnd()
{
    button->setEnabled(true);
}

void HelloWindow::ButtonSlot()
{
    Widget *wgt = new Widget();
    wgt->show();
    wgt->SetPersoneImage();
    wgt->SetPersoneStat();
    this->close();
}
