#ifndef QUESTION_H
#define QUESTION_H

#include "answerMaker.h"

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    explicit Question(QObject *parent = nullptr);
    Question(QString XMLString);
    Question(const Question&);
    Question& operator=(const Question&);
    Question(Question&&);

    void SetText(QString&);
    void AddAnswer(AnswerMaker&);

    QString GetText();
    QVector<AnswerMaker> GetVectorAnswers();

    QString Serialize(QString &ret);
signals:

private:
    qint16 id;
    QString text;
    QVector<AnswerMaker> answers;
};

#endif // QUESTION_H
