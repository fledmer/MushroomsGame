#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QPushButton>

class MessageWidget: public QWidget
{
    Q_OBJECT
public:
    MessageWidget(const QString &text);
    QPushButton *pushButton;
//public slots:
    //void exitSlot();
};

#endif // MESSAGEWIDGET_H
