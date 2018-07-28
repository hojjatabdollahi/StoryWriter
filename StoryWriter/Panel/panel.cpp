#include "panel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <nodes/FlowScene>
#include <nodes/Connection>
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

void Panel::setScene(QtNodes::FlowScene *scene){
    this->_scene = scene;
}


QList<QtNodes::Node *> Panel::getParents(QtNodes::Node &n){
    QList<QtNodes::Node *>  result;
    for(auto con : _scene->connections()){
        if(con.second->getNode(QtNodes::PortType::In)->id()==n.id()){
            result.append(con.second->getNode(QtNodes::PortType::Out));
        }
    }
    return result;
}

QList<QtNodes::Node *> Panel::getChildren(QtNodes::Node &n){
    QList<QtNodes::Node *>  result;
    for(auto con : _scene->connections()){
        if(con.second->getNode(QtNodes::PortType::Out)->id()==n.id()){
            result.append(con.second->getNode(QtNodes::PortType::In));
        }
    }
    return result;
}

void Panel::nodeSelected(QtNodes::Node &n){
    qDebug() << "node selected: " << n.id() ;
    qDebug() << "This node has: " << getParents(n).count() << " parents and " << getChildren(n).count() << " children.";

}
