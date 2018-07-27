#include "panel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
Panel::Panel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *hl = new QVBoxLayout;
    QLabel *topLabel = new QLabel("Everything should be disabled until you select a node and here is more text");
    topLabel->setWordWrap(true);
    hl->addWidget(topLabel);
    _editor = new TextEdit(this);
    _editor->setMinimumWidth(100);
    _editor->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    hl->addWidget(_editor);
    hl->addWidget(new QPushButton("Hello"));
    this->setLayout(hl);
}
