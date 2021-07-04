#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>

class MessageWidget: public QWidget
{
    Q_OBJECT
public:
    MessageWidget(const QString &text);
//public slots:
    //void exitSlot();
};

#endif // MESSAGEWIDGET_H
