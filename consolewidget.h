#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>
#include <QTextEdit>

class ConsoleWidget: public QTextEdit
{
     Q_OBJECT
public:
    QTimer *timer;
    QString consolePrePrint;
    int fontSize;
    ConsoleWidget();
    void PrintText(const QString &text, int speed = 80, int textSize = 20);
    void SetFontSize(int value);
private:
    QVector<QString> stringStack;
    QVector<int> speedStack;
    QVector<int> sizeStack;
    int possiton;
signals:
    void emptyStack();
};

#endif // CONSOLEWIDGET_H
