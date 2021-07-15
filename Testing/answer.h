#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>
#include <QXmlStreamReader>

class Answer : public QObject
{
    Q_OBJECT
public:
    explicit Answer(QObject *parent = nullptr);
    Answer(const Answer&);

    QString GetText() const;

    bool IsCorrect() const;

    static Answer Unserialize(QXmlStreamReader &xmlReader);
signals:

private:
    Answer(qint16 id,QString text,bool is_correct);
    qint16 id = -1;
    QString text = "";
    bool is_correct = false;
};

#endif // ANSWER_H
