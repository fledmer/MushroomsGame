#include "channel.h"
#include <random>
#include <time.h>
#include <QList>
#include <hackgamewidget.h>
#include <dialogwidget.h>
#include <messagewidget.h>

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
    messages = (*(mainWidget->world->messages))[channelLvl-1];
    srand(time(0));
    int fileCount = rand()%3+1;
    int personCount = rand()%3;
    int totalCount = fileCount+personCount+rand()%15+7+4;

    channelFilling = QVector<int>(totalCount+4,0);
    for(int x = 0; x < fileCount;x++){
        int value = rand()%totalCount+3;
        if(channelFilling[value] == 0)
            channelFilling[rand()%totalCount] = 1;
        else
            x--;
    }
    for(int x = 0; x < fileCount;x++){
        int value = rand()%totalCount+3;
        if(channelFilling[value] == 0)
            channelFilling[rand()%totalCount] = 2;
        else
            x--;
    }

    qDebug() << channelFilling;
    qDebug() << this;
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
     connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(messageEnd2()));
     int money = rand() % 1000 + 1000;
     workWidget->textEdit->PrintText("Взлом удался, получен документ: " + QString::number(3-channelLvl) + " уровня\n");
     workWidget->textEdit->PrintText("и " + QString::number(money) + " рублей\n");
     player->changeMoney(money);
}

void Channel::finding()
{
    //qDebug() << inChannelPosition << channelFilling[inChannelPosition];
    if(inChannelPosition == channelFilling.size()){
        workWidget->textEdit->PrintText("Сигнал канала потерян...\n");
        workWidget->unMuteAllWidgets();
        delete this;
    }
    else if(channelFilling[inChannelPosition] == 0){
        isFind = true;
        workWidget->textEdit->PrintText(dialogs[rand()%dialogs.size()]+"\n",100);
    }
    else if(channelFilling[inChannelPosition] == 1){
        disconnect(workWidget->textEdit,SIGNAL(emptyStack()),this,SLOT(messageEnd1()));
        DialogWidget *dw = new DialogWidget("Найден зашифрованный файл, начать взлом ?");
        dw->show();
        dw->setFocus();
        connect(dw,SIGNAL(choiseSignal(bool)),SLOT(choiseWidgetSlot(bool)));
    }
    else if(channelFilling[inChannelPosition] == 2){
        workWidget->textEdit->PrintText("TEST DIALOGS \n");
    }
    inChannelPosition++;
}

void Channel::messageEnd1()
{
    finding();
}

void Channel::messageEnd2()
{
    disconnect(workWidget->textEdit,SIGNAL(emptyStack()),this,SLOT(messageEnd2()));
    player->changeMind(-10*channelLvl);
    mainWidget->SetPersoneStat();
    //MessageWidget *message = new MessageWidget(messages[rand()%messages.size()]);
    MessageWidget *message = new MessageWidget("Дмитрий урич сын прикола\n");
    message->show();
    message->setFocus();
    qDebug() << message->pushButton;
    connect(message->pushButton,SIGNAL(clicked()),this,SLOT(messageEnd2a1()));

}

void Channel::messageEnd2a1()
{
    connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(messageEnd1()));
    workWidget->textEdit->PrintText("От прочтения файла вы чувствуете страх и ужас...\n");
    workWidget->textEdit->PrintText("Возврат на канал...\n");

}

void Channel::choiseWidgetSlot(bool value)
{
    if(value){
        HackGameWidget *miniGame = new HackGameWidget(8+rand()%(channelLvl*3),4+rand()%4);
        miniGame->parentChannel = this;
        miniGame->StartGame();
        miniGame->Update();
        miniGame->show();
        miniGame->setFocus();
    }
    else
    {
        emit nextMessage();
    }
}

