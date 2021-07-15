#include "simpletestreport.h"

SimpleTestReport::SimpleTestReport()
{

}

void SimpleTestReport::SetCountTrueAnswers(int i)
{
    countTrueAnswers = i;
}

void SimpleTestReport::SetCountAnswers(int i)
{
    countAnswers = i;
}

QString SimpleTestReport::ToPlainText()
{
    return "Тест завершён!\n"\
            "Правильных ответов:"+QString::number(countTrueAnswers)+"/"+QString::number(countAnswers);
}
