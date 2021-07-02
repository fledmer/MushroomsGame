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
    int dialogCount = rand()%5+4;
    qDebug() << *(mainWidget->world->dialogs);
    QStringList dialogs = (*(mainWidget->world->dialogs))[LVL-1];
    qDebug() << dialogs.size();
    workWidget->textEdit->consolePrePrint = " ";
    //workWidget->textEdit->SetFontSize(15);
    connect(workWidget->textEdit,SIGNAL(emptyStack()),SLOT(makeGame()));
    for(int x = 0; x < dialogCount;x++){
        workWidget->textEdit->PrintText(dialogs[rand()%(dialogs.count())]);
        workWidget->textEdit->PrintText("\n");
    }
    qDebug() << "HHH";

}

void Channel::makeGame()
{
        qDebug() << "HHH";
    WorkWidget *oldWorkWidget = workWidget;

    mainWidget->mainWidget = new HackGameWidget(mainWidget);
    mainWidget->mainWidget->show();
    workWidget->unMuteAllWidgets();

}
