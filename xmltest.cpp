#include "simpleanswer.h"
#include "simplequest.h"
#include "simpletestreport.h"
#include "simpleuseranswer.h"
#include "xmltest.h"



XMLTest::XMLTest(QFile *XmlFile):report(new SimpleTestReport())
{
    QXmlStreamReader reader(XmlFile);
    reader.readNextStartElement();

    if(reader.name() != "test") throw new std::invalid_argument("xmlReader");

// В будущем использовать для обработки атрибутов теста
//    for(const QXmlStreamAttribute &attr: xmlReader.attributes()) {
//        QString attribute_value = attr.value().toString();
//    }

    while (!(reader.isEndElement() && reader.name()=="test")) {
        QStringRef name = reader.name();
        if(name == "question"){
            questions.append(ReadQuestion(reader));
            userAnswers.append(new SimpleUserAnswer(questions.last()));
        }
        reader.readNext();
    }
}

void XMLTest::Start()
{
    BaseTest::Start();
    SetCurrentQuest(0);
}

void XMLTest::Complete()
{
    BaseTest::Complete();
    report->SetCountAnswers(questions.count());
    int i = 0;
    for(auto ua : userAnswers){
        if(ua->IsCorrect())++i;
    }
    report->SetCountTrueAnswers(i);
}

BaseTestReport *XMLTest::GetReport()
{
    return report;
}

const BaseQuest *XMLTest::CurrentQuest() const
{
    return questions.at(index);
}

qint16 XMLTest::CurrentQuestIndex() const
{
    return index;
}

void XMLTest::SetCurrentQuest(qint16 index)
{
    if(!(0<= index && index<questions.count())) throw nullptr; //ОШИБКА!!!!!
    this->index = index;
}

BaseUserAnswer *XMLTest::GetCurrentUserAnswer()
{
    return userAnswers[index];
}

int XMLTest::GetCountQuests() const
{
    return questions.count();
}

const BaseQuest *XMLTest::ReadQuestion(QXmlStreamReader &reader)
{
    if(reader.name() != "question") throw new std::invalid_argument("xmlReader");

    QVector<const BaseAnswer*> answers;
    quint16 id = -1;
    QString text = "";
    BaseQuest::QuestType type = BaseQuest::QuestType::Error;

    for(const QXmlStreamAttribute &attr: reader.attributes()) {
        QString attribute_value = attr.value().toString();
        if(attr.name().toString() == "id"){
            id = attribute_value.toInt();
        }
        if(attr.name().toString() == "type"){
            type = QVariant(text).value<BaseQuest::QuestType>();
        }
    }

    while (!(reader.isEndElement() && reader.name()=="question")) {
        QStringRef name = reader.name();
        if( name == "text")
        {
            text = reader.readElementText(QXmlStreamReader::IncludeChildElements);
        }
        if(name == "answer"){
            answers.append(ReadAnswer(reader));
        }
        reader.readNext();
    }
    return new SimpleQuest(id, text, answers);
}

const BaseAnswer *XMLTest::ReadAnswer(QXmlStreamReader &reader)
{
    bool is_correct = false;
    qint16 id = -1;
    QString text = "";
    if(reader.name() == "answer")
    {
        for(const QXmlStreamAttribute &attr: reader.attributes()) {
            QString attribute_value = attr.value().toString();
            if(attr.name().toString() == "is_correct") {
                is_correct = ((QString::compare(attribute_value , "true") == 0) ? true : false);

            }
            if(attr.name().toString() == "id"){
                id = attribute_value.toInt();
            }
        }
        text = reader.readElementText(QXmlStreamReader::IncludeChildElements);
    }
    return new SimpleAnswer(id,text,is_correct);
}
