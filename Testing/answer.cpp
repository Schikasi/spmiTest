#include "Testing/answer.h"

QString Answer::GetText() const{
    return this->text;
}
bool Answer::IsCorrect() const{
    return this->is_correct;
}
Answer Answer::Unserialize(QXmlStreamReader &xmlReader){
    bool is_correct = false;
    qint16 id = -1;
    QString text = "";
    if(xmlReader.name() == "answer")
    {
        for(const QXmlStreamAttribute &attr: xmlReader.attributes()) {
            QString attribute_value = attr.value().toString();
            if(attr.name().toString() == "is_correct") {
                is_correct = ((QString::compare(attribute_value , "true") == 0) ? true : false);

            }
            if(attr.name().toString() == "id"){
                id = attribute_value.toInt();
            }
        }
        text = xmlReader.readElementText(QXmlStreamReader::IncludeChildElements);
    }
    Answer  a(id,text,is_correct);
    return a;
}

Answer::Answer(qint16 id, QString text, bool is_correct):id(id),text(text),is_correct(is_correct)
{
}

Answer::Answer(const Answer &rhs):id(rhs.id),text(rhs.text),is_correct(rhs.is_correct)
{
}
