#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>
#include <QTextEdit>

class ConsoleWidget: public QTextEdit
{
public:
    QTimer *timer;
    QString consolePrePrint;
    ConsoleWidget();
    void PrintText(const QString &text, int speed = 80);
private:
    QVector<QString> stringStack;
    QVector<int> speedStack;
    int possiton;
};

#endif // CONSOLEWIDGET_H
