#ifndef CHATDATA_H
#define CHATDATA_H

#include <nodes/NodeDataModel>

using QtNodes::NodeDataType;
using QtNodes::NodeData;

class ChatData: public NodeData
{
public:
    ChatData()
        {}
    ChatData(QString const &text): _text(text){}


    NodeDataType type() const override
    { return NodeDataType {"text", "Text"}; }

    QString text() const
    { return _text; }

    void setData(QString const &text){ _text = text;}

private:
    QString _text;

};

#endif // CHATDATA_H

