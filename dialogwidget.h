#ifndef DIALOGWIDGET_H
#define DIALOGWIDGET_H

#include <QWidget>

class DialogWidget: public QWidget
{
    Q_OBJECT
public:
    DialogWidget(const QString &message);
public slots:
    void choiceFalseSlot();
    void choiceTrueSlot();
signals:
    void choiseSignal(bool);
};

#endif // DIALOGWIDGET_H
