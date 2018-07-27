#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QCompleter>
#include <QTextEdit>
#include <QAbstractItemModel>
#include "highlighter.h"
#include <QDebug>
#include <nodes/Node>
class TextEdit : public QTextEdit
{Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;
    void setupEditor();
protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
    void insertCompletion(const QString &completion);
public slots:
    void nodeSelected(QtNodes::Node &n);
private:
    QString textUnderCursor() const;

private:
    QCompleter *c;


    //QTextEdit *editor;
    Highlighter *highlighter;

    QAbstractItemModel *modelFromFile(const QString& fileName);
    QAbstractItemModel *modelFromMe();

};

#endif // TEXTEDIT_H
