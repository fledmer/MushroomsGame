#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include <QWidget>
#include <QPushButton>

class HelloWindow : public QWidget
{
    Q_OBJECT
public:
    HelloWindow();
    QPushButton *button;
public slots:
    void MessageEnd();
    void ButtonSlot();
};

#endif // HELLOWINDOW_H
