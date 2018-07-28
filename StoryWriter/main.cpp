#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>
#include <nodes/TypeConverter>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMenuBar>

#include <nodes/DataModelRegistry>

#include "NumberSourceDataModel.hpp"
#include "NumberDisplayDataModel.hpp"
#include "AdditionModel.hpp"
#include "SubtractionModel.hpp"
#include "MultiplicationModel.hpp"
#include "DivisionModel.hpp"
#include "ModuloModel.hpp"
#include "Converters.hpp"
#include "Panel/panel.h"
#include "Nodes/ConditionDataModel.h"
#include "Nodes/userpromptdatamodel.h"

using QtNodes::DataModelRegistry;
using QtNodes::FlowScene;
using QtNodes::FlowView;
using QtNodes::ConnectionStyle;
using QtNodes::TypeConverter;
using QtNodes::TypeConverterId;

static std::shared_ptr<DataModelRegistry>
registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();
    ret->registerModel<NumberSourceDataModel>("Sources");

    ret->registerModel<NumberDisplayDataModel>("Displays");

    ret->registerModel<AdditionModel>("Operators");

    ret->registerModel<SubtractionModel>("Operators");

    ret->registerModel<MultiplicationModel>("Operators");

    ret->registerModel<DivisionModel>("Operators");
    ret->registerModel<ConditionDataModel>("Intermediate");
    ret->registerModel<UserPromptDataModel>("Intermediate");
    ret->registerModel<ModuloModel>("Operators");

    ret->registerTypeConverter(std::make_pair(DecimalData().type(),
                                              IntegerData().type()),
                               TypeConverter{DecimalToIntegerConverter()});



    ret->registerTypeConverter(std::make_pair(IntegerData().type(),
                                              DecimalData().type()),
                               TypeConverter{IntegerToDecimalConverter()});

    return ret;
}


static
void
setStyle()
{
    ConnectionStyle::setConnectionStyle(
                R"(
                {
                "ConnectionStyle": {
                "ConstructionColor": "gray",
                "NormalColor": "black",
                "SelectedColor": "gray",
                "SelectedHaloColor": "deepskyblue",
                "HoveredColor": "deepskyblue",

                "LineWidth": 3.0,
                "ConstructionLineWidth": 2.0,
                "PointDiameter": 10.0,

                "UseDataDefinedColors": true
                }
                }
                )");
}


int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    setStyle();

    QWidget *mainWidget = new QWidget;

    auto menuBar    = new QMenuBar();
    auto saveAction = menuBar->addAction("Save..");
    auto loadAction = menuBar->addAction("Load..");









    QVBoxLayout *l = new QVBoxLayout;//(&mainWidget);

    l->addWidget(menuBar);





    QHBoxLayout *hl = new QHBoxLayout;
    TextEdit block2;
    //  block.setMinimumWidth(100);
    //  block.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    Panel block;
    hl->addWidget(&block);

    auto scene = new FlowScene(registerDataModels(), mainWidget);
    hl->addWidget(new FlowView(scene));
    block.setScene(scene);
    //  l->addWidget(new FlowView(scene));
    //  l->addLayout(hl);
    l->setContentsMargins(0, 0, 0, 0);
    l->setSpacing(0);


    QObject::connect(scene, &FlowScene::nodeDoubleClicked, &block, &Panel::nodeSelected);

    QObject::connect(saveAction, &QAction::triggered,
                     scene, &FlowScene::save);

    QObject::connect(loadAction, &QAction::triggered,
                     scene, &FlowScene::load);

    mainWidget->setWindowTitle("Dataflow tools: simplest calculator");
    mainWidget->resize(800, 600);
    mainWidget->showNormal();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addLayout(l);
    mainLayout->addLayout(hl);
    mainWidget->setLayout(mainLayout);

    return app.exec();
}
