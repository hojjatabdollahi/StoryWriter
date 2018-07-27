#include "textedit.h"

#include "textedit.h"
#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QApplication>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>
#include <QStringListModel>

#include <nodes/NodeDataModel>
TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent), c(nullptr)
{
//    setPlainText(tr("This TextEdit provides autocompletions for words that have more than"
//                    " 3 characters. You can trigger autocompletion using ") +
//                 QKeySequence("Ctrl+E").toString(QKeySequence::NativeText));
//    myFrame->setStyleSheet();
    setStyleSheet("QTextEdit {background-color: Cornsilk; border: 1px solid black; border-radius: 5px;}");
    setupEditor();
}

TextEdit::~TextEdit()
{
}


QAbstractItemModel *TextEdit::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(c);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, c);
}

QAbstractItemModel *TextEdit::modelFromMe()
{


    QStringList words;
    words << "get";
    words << "set";
    words << "think";
    words << "star";

    return new QStringListModel(words, c);
}


void TextEdit::setupEditor()
{


    c = new QCompleter(this);
    //    completer->setModel(modelFromFile(":/resources/wordlist.txt"));
    c->setModel(modelFromMe());
    c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    c->setWrapAround(false);
    c->setFilterMode(Qt::MatchFlag::MatchStartsWith);
//    c->setCompletionMode(QCompleter::CompletionMode::InlineCompletion);
    this->setCompleter(c);

    QFont font;
    font.setFamily("Segoe UI");
    font.setFixedPitch(true);
    font.setPointSize(10);

    //    completingTextEdit = new QTextEdit;
    this->setFont(font);

    highlighter = new Highlighter(this->document());

}


void TextEdit::setCompleter(QCompleter *completer)
{
    if (c)
        QObject::disconnect(c, nullptr, this, 0);

    c = completer;

    if (!c)
        return;

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, SIGNAL(activated(QString)),
                     this, SLOT(insertCompletion(QString)));
}

QCompleter *TextEdit::completer() const
{
    return c;
}

void TextEdit::insertCompletion(const QString& completion)
{
    if (c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    //TODO: I removed this, isn't it important?
//    tc.movePosition(QTextCursor::Left);
//    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}

QString TextEdit::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void TextEdit::focusInEvent(QFocusEvent *e)
{
    if (c)
        c->setWidget(this);
    QTextEdit::focusInEvent(e);
}

void TextEdit::keyPressEvent(QKeyEvent *e)
{
    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
        default:
            break;
        }
    }

    bool isShortcut = ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!c || !isShortcut) // do not process the shortcut when we have a completer
        QTextEdit::keyPressEvent(e);

    const bool ctrlOrShift = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);
    if (!c || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
    bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

//    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
//                        || eow.contains(e->text().right(1)))) {
//        c->popup()->hide();
//        return;
//    }

    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 2
                        )) {
        c->popup()->hide();
        return;
    }


    if (completionPrefix != c->completionPrefix()) {
        c->setCompletionPrefix(completionPrefix);
        c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(c->popup()->sizeHintForColumn(0)
                + c->popup()->verticalScrollBar()->sizeHint().width());
    c->complete(cr); // popup it up!
}

void TextEdit::nodeSelected(QtNodes::Node &n){
    qDebug() << "node selected: " << n.nodeDataModel()->save() ;
}
