#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

Test::Test(QVector<Question> questions): questions(questions)
{

}

Test::Test(const Test &rhs): QObject(rhs.parent()), questions(rhs.questions)
{

}

Question &Test::GetQuestion(qint16 number)
{
    return questions[number-1];
}

Test Test::Unserialize(QXmlStreamReader &xmlReader)
{

    if(xmlReader.name() != "test") throw new std::invalid_argument("xmlReader");
    QVector<Question> questions = QVector<Question>();

    // В будущем использовать для обработки атрибутов теста
//    for(const QXmlStreamAttribute &attr: xmlReader.attributes()) {
//        QString attribute_value = attr.value().toString();
//    }

    while (!(xmlReader.isEndElement() && xmlReader.name()=="test")) {
        QStringRef name = xmlReader.name();
        if(name == "question"){
            questions.append(Question::Unserialize(xmlReader));
        }
        xmlReader.readNext();
    }
    Test t(questions);
    return t;
}

void Test::StartTest()
{

}

float Test::CompleteTest() const
{
    int countQuestions = questions.count();
    int countTrueAnswers = 0;
    for(const Question& q :questions){
        if(q.IsCorrect()) ++countTrueAnswers;
    }
    return countTrueAnswers/countQuestions;
}
