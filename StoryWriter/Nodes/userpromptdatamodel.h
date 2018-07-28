#ifndef USERPROMPTDATAMODEL_H
#define USERPROMPTDATAMODEL_H

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>
#include <nodes/NodeDataModel>
#include <iostream>

//TODO: Remove this and add a label
#include "TextEdit/textedit.h"

class ChatData;

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

class UserPromptDataModel
        : public NodeDataModel
      {
        Q_OBJECT
public:
    UserPromptDataModel();
    virtual ~UserPromptDataModel(){}
public:

  QString
  caption() const override
  { return QStringLiteral("User Prompt"); }

  bool
  captionVisible() const override
  { return false; }

  QString
  name() const override
  { return QStringLiteral("UserPrompt"); }

public:

  QJsonObject
  save() const override;

  void
  restore(QJsonObject const &p) override;

public:

  unsigned int
  nPorts(PortType portType) const override;

  NodeDataType
  dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>
  outData(PortIndex port) override;

  void
  setInData(std::shared_ptr<NodeData>, int) override
  { }

  QWidget *
  embeddedWidget() override { return _editor; }

private slots:

  void
  onTextEdited();

private:

  TextEdit * _editor;

};

#endif // USERPROMPTDATAMODEL_H
