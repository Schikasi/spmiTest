#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QVector>
#include <Testing/question.h>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    Test(QVector<Question> questions);
    Test(const Test&rhs);

    Question&  GetQuestion(qint16 number);

    static Test Unserialize(QXmlStreamReader &xmlReader);

    void StartTest();

    float CompleteTest() const;
signals:

private:
    QVector<Question> questions;
    qint16 countQuestions = 0;

};

#endif // TEST_H
