#include "ConditionDataModel.h"


//TODO: create a better Data
#include "DecimalData.hpp"


ConditionDataModel::ConditionDataModel() : _widget(new ConditionWidget())
{    
}


unsigned int
ConditionDataModel::
nPorts(PortType portType) const
{
  unsigned int result = 1;
 //TODO: check to see if the ports can change dynamically
  switch (portType)
  {
    case PortType::In:
      result = 1;
      break;

    case PortType::Out:
      result = 4;
      break;

    default:
      break;
  }

  return result;
}



NodeDataType
ConditionDataModel::
dataType(PortType, PortIndex) const
{
    //TODO: Fix this
  return DecimalData().type();
}


std::shared_ptr<NodeData>
ConditionDataModel::
outData(PortIndex)
{
  std::shared_ptr<NodeData> ptr;
  return ptr;
}


void
ConditionDataModel::
setInData(std::shared_ptr<NodeData> data, int)
{
    //TODO: Fix this

    //TODO: The in data could be the name of the parent (or the code which we will alter use in "that"



//  auto numberData = std::dynamic_pointer_cast<DecimalData>(data);

//  if (numberData)
//  {
//    modelValidationState = NodeValidationState::Valid;
//    modelValidationError = QString();
//    _label->setText(numberData->numberAsText());
//  }
//  else
//  {
//    modelValidationState = NodeValidationState::Warning;
//    modelValidationError = QStringLiteral("Missing or incorrect inputs");
//    _label->clear();
//  }

//  _label->adjustSize();
}


NodeValidationState
ConditionDataModel::
validationState() const
{
  return modelValidationState;
}




bool
ConditionDataModel::
resizable() const
{
  return true;
}

QString
ConditionDataModel::
validationMessage() const
{
  return modelValidationError;
}
