#ifndef QUESTION_H
#define QUESTION_H

#include "answer.h"

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    explicit Question(QObject *parent = nullptr);

    Question(quint16 id, QString text, QVector<Answer> answers);
    Question(const Question&);
    Question(Question&&);
    Question operator=(const Question&);

    QVector<Answer> getAnswers() const;

    QString getText() const;

    qint16 getId() const;

    Answer *getUserAnswer();
    void setUserAnswer(Answer * value);

    bool IsCorrect() const;

    static Question Unserialize(QXmlStreamReader &xmlReader);

signals:

private:
    qint16 id = -1;
    QString text = "";
    QVector<Answer> answers = QVector<Answer>();
    Answer * userAnswer = nullptr;
};

#endif // QUESTION_H
