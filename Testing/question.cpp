#include "Testing/question.h"

#include <stdexcept>

Question::Question(QObject *parent) : QObject(parent)
{

}

Question::Question(quint16 id, QString text, QVector<Answer> answers):id(id),text(text),answers(answers)
{

}

Question::Question(const Question &rhs):id(rhs.id),text(rhs.text),answers(rhs.answers)
{

}

Question::Question(Question &&rhs):id(rhs.id),text(rhs.text),answers(rhs.answers)
{
}

QVector<Answer> Question::getAnswers() const
{
    return answers;
}

QString Question::getText() const
{
    return text;
}

qint16 Question::getId() const
{
    return id;
}

Answer * Question::getUserAnswer()
{
    return userAnswer;
}

void Question::setUserAnswer(Answer *value)
{

    userAnswer = value;
}

bool Question::IsCorrect() const
{
    if(userAnswer!=nullptr)
        return userAnswer->IsCorrect();
    return false;
}

Question Question::Unserialize(QXmlStreamReader &xmlReader)
{
    if(xmlReader.name() != "question") throw new std::invalid_argument("xmlReader");
    QVector<Answer> answers;
    qint16 id = -1;
    QString text = "";

    for(const QXmlStreamAttribute &attr: xmlReader.attributes()) {
        QString attribute_value = attr.value().toString();
        if(attr.name().toString() == "id"){
            id = attribute_value.toInt();
        }
    }

    while (!(xmlReader.isEndElement() && xmlReader.name()=="question")) {
        QStringRef name = xmlReader.name();
        if( name == "text")
        {
            text = xmlReader.readElementText(QXmlStreamReader::IncludeChildElements);
        }
        if(name == "answer"){
            answers.append(Answer::Unserialize(xmlReader));
        }
        xmlReader.readNext();
    }

    Question q(id, text, answers);
    return q;
}
