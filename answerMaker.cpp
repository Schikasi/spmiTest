#include "answerMaker.h"

#include <QXmlStreamWriter>

AnswerMaker::AnswerMaker(QObject *parent) : QObject(parent)
{

}

///
/// \brief Answer::Answer конструктор копирования
/// \param other
///
AnswerMaker::AnswerMaker(const AnswerMaker &other)
{
    this->text = other.text;
    this->is_correct = other.is_correct;
    this->id = other.id;
}
///
/// \brief Answer::Answer конструктор перемещения
/// \param other
///
AnswerMaker::AnswerMaker(AnswerMaker && other)
{
    this->text = other.text;
    this->is_correct = other.is_correct;
    this->id = other.id;
}

///
/// \brief Answer::operator = оператор присваивания копирования
/// \param other
/// \return
///
AnswerMaker &AnswerMaker::operator=(const AnswerMaker &other)
{
    this->text = other.text;
    this->is_correct = other.is_correct;
    this->id = other.id;
    return *this;
}

void AnswerMaker::SetText(QString &text)
{
    this->text = QString(text);
}

void AnswerMaker::SetCorrect(bool correct)
{
    this->is_correct = correct;
}

QString AnswerMaker::GetText()
{
    return text;
}

bool AnswerMaker::IsCorrect()
{
    return is_correct;
}


QString AnswerMaker::Serialize(QString & ret)
{
    QXmlStreamWriter r(&ret);
    r.setAutoFormatting(true);
    r.writeStartElement("answer");
    r.writeAttribute("is_correct",is_correct?"true":"false");
    r.writeCharacters(text);
    r.writeEndElement();
    return ret;
}
