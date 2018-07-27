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

signals:

public slots:


private:
    TextEdit *_editor;
};

#endif // PANEL_H
