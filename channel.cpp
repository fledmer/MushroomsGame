#include "channel.h"
#include <random>
#include <time.h>
#include <QList>
#include <hackgamewidget.h>

Channel::Channel(Widget *mainWidget,WorkWidget *workWidget, int LVL):
    workWidget(workWidget),
    mainWidget(mainWidget),
    LVL(LVL)
{
    workWidget->MuteAllWidgets();
    srand(time(0));
    int dialogCount = 1;
    //int dialogCount = rand()%5+4;
    //qDebug() << *(mainWidget->world->dialogs);
    QStringList dialogs = (*(mainWidget->world->dialogs))[LVL-1];
    //qDebug() << dialogs.size();
    workWidget->textEdit->consolePrePrint = " ";
    //workWidget->textEdit->SetFontSize(15);
    connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(makeGame()));
    for(int x = 0; x < dialogCount;x++){
        workWidget->textEdit->PrintText(dialogs[rand()%(dialogs.count())]);
        workWidget->textEdit->PrintText("\n");
    }

}

void Channel::succesHack()
{
    qDebug() << "SUCESS HACK";
}

void Channel::makeGame()
{
    HackGameWidget *hackGame = new HackGameWidget(4,4);
    hackGame->parentChannel = this;
    hackGame->StartGame();
    hackGame->Update();
    //workWidget->mainLayout->addWidget(hackGame,0,1,2,5);
    hackGame->show();
    connect(mainWidget,SIGNAL(keyPressSignal(QKeyEvent*)),hackGame,SLOT(keyPressSlot(QKeyEvent*)));
}

