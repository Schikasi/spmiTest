#include "basetest.h"

BaseTest::BaseTest(QObject *parent) : QObject(parent)
{

}

void BaseTest::Start()
{
    emit TestStarted();
}

void BaseTest::Complete()
{
    emit TestCompleted();
}

void BaseTest::SetCurrentQuest(qint16 index)
{
    emit CurrentQuestChanged(index);
}
