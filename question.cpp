#include "question.h"

#include <qxmlstream.h>

Question::Question(QObject *parent) : QObject(parent)
{

}

Question::Question(const Question &other)
{
    this->id = other.id;
    this->text = other.text;
    this->answers = other.answers;
}

Question& Question::operator=(const Question & other)
{
    this->id = other.id;
    this->text = other.text;
    this->answers = other.answers;
    return *this;
}

Question::Question(Question && other)
{
    this->id = other.id;
    this->text = other.text;
    this->answers = other.answers;
}

void Question::SetText(QString &text)
{
    this->text = QString(text);
}

void Question::AddAnswer(AnswerMaker &answer)
{
    this->answers.append(answer);
}

QString Question::Serialize(QString & ret)
{
    QXmlStreamWriter r(&ret);
    r.setAutoFormatting(true);
    r.writeStartElement("question");
    r.writeTextElement("text",text);
    for(auto a: answers){
        a.Serialize(ret);
    }
    r.writeEndElement();
    return ret;

}
