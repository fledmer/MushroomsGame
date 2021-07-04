#include "dialogwidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>


DialogWidget::DialogWidget(const QString &message)
{
    this->setGeometry(760,440,200,100);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QLabel *label = new QLabel(message);
    mainLayout->addWidget(label);
    {
        QHBoxLayout *layout = new QHBoxLayout();
        QPushButton *pushButton1 = new QPushButton();
        pushButton1->setText("Да");
        QPushButton *pushButton2 = new QPushButton();
        pushButton2->setText("Нет");
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
}

void DialogWidget::choiceTrueSlot()
{
    emit choiseSignal(true);
}

