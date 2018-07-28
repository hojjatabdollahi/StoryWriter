#ifndef CONDITION_H
#define CONDITION_H

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

#include "Nodes/widgets/conditionwidget.h"


using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;


class ConditionDataModel  : public NodeDataModel
{
     Q_OBJECT

public:
    ConditionDataModel();

    virtual ~ConditionDataModel() {}

public:
    QString
    caption() const override
    { return QStringLiteral("Condition"); }

    bool
    captionVisible() const override
    { return false; }

    QString
    name() const override
    { return QStringLiteral("Condition"); }

public:
    unsigned int
    nPorts(PortType portType) const override;

    bool resizable() const override;

    NodeDataType
    dataType(PortType portType,
             PortIndex portIndex) const override;

    std::shared_ptr<NodeData>
    outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData> data, int) override;

    QWidget *
    embeddedWidget() override { return _widget; }

    NodeValidationState
    validationState() const override;

    QString
    validationMessage() const override;

private:

  NodeValidationState modelValidationState = NodeValidationState::Warning;
  QString modelValidationError = QStringLiteral("Missing or incorrect inputs");

  ConditionWidget * _widget;

};

#endif // CONDITION_H
