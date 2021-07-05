#include "dialogwidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>


DialogWidget::DialogWidget(const QString &message)
{
    this->setGeometry(760,440,200,100);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setStyleSheet("background-color: black;");
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QLabel *label = new QLabel(message);
    label->setStyleSheet("background-color: black;color: #68da23;font-size:30px");
    mainLayout->addWidget(label);
    {
        QHBoxLayout *layout = new QHBoxLayout();
        QPushButton *pushButton1 = new QPushButton();
        pushButton1->setText("Да");
        pushButton1->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;font-size:20px");
        QPushButton *pushButton2 = new QPushButton();
        pushButton2->setText("Нет");
        pushButton2->setStyleSheet("background-color: black;color: #68da23;border-style: solid;border-width:1px;border-color: white;font-size:20px");
        connect(pushButton1,SIGNAL(clicked()),this,SLOT(choiceTrueSlot()));
        connect(pushButton2,SIGNAL(clicked()),this,SLOT(choiceFalseSlot()));
        layout->addWidget(pushButton1);
        layout->addWidget(pushButton2);
        mainLayout->addLayout(layout);
    }

    setLayout(mainLayout);
}

void DialogWidget::choiceFalseSlot()
{
    emit choiseSignal(false);
    delete this;
}

void DialogWidget::choiceTrueSlot()
{
    emit choiseSignal(true);
    delete this;
}

