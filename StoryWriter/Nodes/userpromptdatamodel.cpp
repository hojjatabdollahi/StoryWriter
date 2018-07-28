#include "userpromptdatamodel.h"

#include <QtCore/QJsonValue>

#include "Nodes/chatdata.h"

UserPromptDataModel::UserPromptDataModel()
    :_editor(new TextEdit())
{
  //_lineEdit->setValidator(new QDoubleValidator());

  //_lineEdit->setMaximumSize(_lineEdit->sizeHint());
//  _data = new ChatData("Empty");
  connect(_editor, &TextEdit::textChanged,
          this, &UserPromptDataModel::onTextEdited);
  _editor->setText("0.0");
}

QJsonObject
UserPromptDataModel::
save() const
{
  QJsonObject modelJson = NodeDataModel::save();

  if (_editor->toPlainText().length()>0)
    modelJson["pattern"] = _editor->toPlainText();

  return modelJson;
}


void
UserPromptDataModel::
restore(QJsonObject const &p)
{
  QJsonValue v = p["pattern"];

  if (!v.isUndefined())
  {
    QString strUP = v.toString();
    _editor->setText(strUP);
  }
}


unsigned int
UserPromptDataModel::
nPorts(PortType portType) const
{
  unsigned int result = 1;

  switch (portType)
  {
    case PortType::In:
      result = 1;
      break;

    case PortType::Out:
      result = 1;
      break;

    default:
      break;
  }

  return result;
}


void
UserPromptDataModel::
onTextEdited()
{
    emit dataUpdated(0);
}


NodeDataType
UserPromptDataModel::
dataType(PortType, PortIndex) const
{
  return ChatData().type();
}


std::shared_ptr<NodeData>
UserPromptDataModel::
outData(PortIndex)
{
  return std::make_shared<ChatData>(_editor->toPlainText());
}
