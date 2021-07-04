#include "consolewidget.h"
#include <QTimer>

ConsoleWidget::ConsoleWidget():QTextEdit(),
    consolePrePrint(">:"),
    fontSize(10),
    stringStack(),
    speedStack(),
    sizeStack(),
    possiton(0)
{
    setReadOnly(true);
    setStyleSheet("border-style:solid;\
    border-width: 1px;\
    border-radius: 10px;\
    border-color: white;");
    setLineWidth(1);
    SetFontSize(20);
    setTextColor(Qt::green);
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer,&QTimer::timeout,[&](){
        if(possiton==0){
            timer->setInterval(speedStack[0]);
            speedStack.pop_front();
            //SetFontSize(sizeStack[0]);
            //sizeStack.pop_front();
        }
        insertPlainText(stringStack[0][possiton]);
        possiton++;
        if(stringStack[0].size() == possiton){
            stringStack.pop_front();
            possiton=0;
            if(stringStack.isEmpty()){
                timer->stop();
                emit emptyStack();
            }
        }
        });
}

void ConsoleWidget::PrintText(const QString &text, int speed, int textSize)
{
    timer->start();
    stringStack  << consolePrePrint << text;
    speedStack << 10 << speed;
    //sizeStack << textSize << textSize;
}

void ConsoleWidget::SetFontSize(int value)
{
    value = value - fontSize;
    if(value < 0)
        zoomOut(-value);
    else
        zoomIn(value);
}
