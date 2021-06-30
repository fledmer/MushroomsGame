#include "consolewidget.h"
#include <QTimer>

ConsoleWidget::ConsoleWidget():QTextEdit(),
    consolePrePrint(">:"),
    stringStack(),
    speedStack(),
    possiton(0)
{
    setReadOnly(true);
    setStyleSheet("border-style:solid;\
    border-width: 1px;\
    border-radius: 10px;\
    border-color: white;");
    setLineWidth(1);
    zoomIn(5);
    setTextColor(Qt::green);
    timer = new QTimer();
    timer->setInterval(80);
    connect(timer,&QTimer::timeout,[&](){
        insertPlainText(stringStack[0][possiton]);
        possiton++;
        if(stringStack[0].size() == possiton){
            stringStack.pop_front();
            timer->setInterval(speedStack[0]);
            speedStack.pop_front();
            possiton=0;
            if(stringStack.isEmpty())
            {
                timer->stop();
            }
        }
        });
}

void ConsoleWidget::PrintText(const QString &text, int speed)
{
    timer->start();
    stringStack  << text;
    speedStack << speed;
}
