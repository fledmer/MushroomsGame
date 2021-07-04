#include "messagewidget.h"
#include <QHBoxLayout>
#include <QLabel>

MessageWidget::MessageWidget(const QString &text):QWidget()
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setStyleSheet("background: black");
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *label = new QLabel(text);
    label->setStyleSheet("background: black; color: red");
    layout->addWidget(label);
    setLayout(layout);
}
