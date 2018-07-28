    #ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include <QWidget>
#include "TextEdit/textedit.h"

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = nullptr);
    void setScene(QtNodes::FlowScene *scene);
    QList<QtNodes::Node *> getParents(QtNodes::Node &n);
    QList<QtNodes::Node *> getChildren(QtNodes::Node &n);
signals:

public slots:
    void nodeSelected(QtNodes::Node &n);

public slots:


private:
    TextEdit *_editor;
    QtNodes::FlowScene * _scene;
};

#endif // PANEL_H
