#include "messagewidget.h"
#include <QVBoxLayout>
#include <QLabel>

MessageWidget::MessageWidget(const QString &text):QWidget()
{
    setWindowTitle("");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setStyleSheet("background: black");
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *label = new QLabel(text);
    label->setStyleSheet("background: black; color: red;font-size: 30px");
    layout->addWidget(label);
    pushButton = new QPushButton(this);
    pushButton->setText("OK");
    pushButton->setStyleSheet("background-color: black;color: red;border-style: solid;border-width:1px;border-color: white;font-size: 30px");
    connect(pushButton,SIGNAL(clicked()),this,SLOT(close()));
    layout->addWidget(pushButton);
    setLayout(layout);
}
