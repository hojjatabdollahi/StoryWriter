#include "conditionwidget.h"
#include <QVBoxLayout>
#include <QLabel>
ConditionWidget::ConditionWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *l = new QVBoxLayout();
    QLabel *label = new QLabel("Hi, this is an example");
    l->addWidget(label);
    this->setLayout(l);
}
