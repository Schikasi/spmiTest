#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QObject>
#include <QWidget>

class TextEdit : public QTextEdit
{
public:
     bool canInsertFromMimeData(const QMimeData* source) const;
     void insertFromMimeData(const QMimeData* source);
     TextEdit(QWidget *parent = nullptr):QTextEdit(parent){}
protected:
     void dropImage(const QUrl &url, const QImage &image);
     void dropTextFile(const QUrl &url);
};

#endif // TEXTEDIT_H
