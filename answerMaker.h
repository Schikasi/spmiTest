#ifndef ANSWERMAKER_H
#define ANSWERMAKER_H

#include <QObject>

class AnswerMaker : public QObject
{
    Q_OBJECT
public:
    explicit AnswerMaker(QObject *parent = nullptr);
    AnswerMaker(const AnswerMaker&);
    AnswerMaker(AnswerMaker&&other);
    AnswerMaker(QString XMLString);
    AnswerMaker& operator=(const AnswerMaker& other);

    void SetText(QString&);
    void SetCorrect(bool);

    QString GetText();
    bool IsCorrect();

    QString Serialize(QString &ret);
signals:

private:
    qint16 id = -1;
    QString text = "";
    bool is_correct = false;
};

#endif // ANSWERMAKER_H
