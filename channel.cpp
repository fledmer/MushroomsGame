#include "channel.h"
#include <random>
#include <time.h>
#include <QList>
#include <hackgamewidget.h>
#include <dialogwidget.h>

Channel::Channel(Widget *mainWidget,WorkWidget *workWidget, int channelLvl):
    workWidget(workWidget),
    mainWidget(mainWidget),
    world(mainWidget->world),
    player(mainWidget->world->mainCharacter),
    channelLvl(channelLvl),
    state(0),
    isFind(false),
    inChannelPosition(0)
{
    workWidget->MuteAllWidgets();
    dialogs = (*(mainWidget->world->dialogs))[channelLvl-1];
    srand(time(0));
    int fileCount = rand()%3+1;
    int personCount = rand()%3;
    int totalCount = fileCount+personCount+rand()%10+4;

    channelFilling = QVector<int>(totalCount,0);
    for(int x = 0; x < fileCount;x++){
        int value = rand()%totalCount;
        if(channelFilling[value] == 0)
            channelFilling[rand()%totalCount] = 1;
        else
            x--;
    }
    for(int x = 0; x < fileCount;x++){
        int value = rand()%totalCount;
        if(channelFilling[value] == 0)
            channelFilling[rand()%totalCount] = 1;
        else
            x--;
    }


    connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(messageEnd1()));
    connect(this,SIGNAL(nextMessage()),SLOT(messageEnd1()));
    emit nextMessage();
    //int dialogCount = rand()%5+4;
    //qDebug() << *(mainWidget->world->dialogs);
    //qDebug() << dialogs.size();
    //workWidget->textEdit->consolePrePrint = " ";
    //workWidget->textEdit->SetFontSize(15);


}

void Channel::succesHack()
{
    int random = rand()%3;
    if(random == 0){
        connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(messageEnd2()));
        workWidget->textEdit->PrintText("Взлом удался, получен документ: " + QString::number(3-channelLvl) + " уровня");
    }
}

void Channel::finding()
{
    if(channelFilling[inChannelPosition] == 0){
        isFind = true;
        workWidget->textEdit->PrintText(dialogs[rand()%dialogs.size()]+"\n",100);
    }
    else if(channelFilling[inChannelPosition] == 1){
        disconnect(workWidget->textEdit,SIGNAL(emptyStack()),this,SLOT(messageEnd1()));
        DialogWidget *dw = new DialogWidget("Найден зашифрованный файл, начать взлом ?");
        dw->show();
        connect(dw,SIGNAL(choiseSignal(bool)),SLOT(choiseWidgetSlot(bool)));
    }
    else if(channelFilling[inChannelPosition] == 2){
        workWidget->textEdit->PrintText("DIALOGS");
    }

    inChannelPosition++;
}

void Channel::messageEnd1()
{
    finding();
}

void Channel::messageEnd2()
{

    player->changeMind(-10*channelLvl);
}

void Channel::choiseWidgetSlot(bool value)
{
    if(value){
        HackGameWidget *miniGame = new HackGameWidget(6+rand()%(channelLvl*3),2+rand()%3);
        miniGame->StartGame();
        miniGame->Update();
    }
    else
    {
        qDebug() << "XEXEEX";
    }
}

