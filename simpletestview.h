#ifndef SIMPLETESTVIEW_H
#define SIMPLETESTVIEW_H

#include <QPushButton>
#include <QWidget>
#include <Widgets/oneofwidget.h>
#include <Widgets/testreportwidget.h>
#include "simplenavigateview.h"
#include "xmlTest.h"

namespace Ui {
class SimpleTestView;
}

class SimpleTestView : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTestView(BaseTest *test, QWidget *parent = nullptr);
    ~SimpleTestView();

    void SetTest(XMLTest * test);
    void ShowPreview();
    void StartTest();
    void PreviousQuestion();
    void NextQuestion();
    void CompleteTest();
    void ShowReport();

    void SetQuestion(qint16 i);
private:
    Ui::SimpleTestView *ui;
    BaseTest *test = nullptr;
    QPushButton *completeTestButton = nullptr;
    QPushButton *startTestButton = nullptr;
    SimpleNavigateView *navigateView;
    OneOfWidget *questView = nullptr;                     //Должен быть базовый класс виджета вопроса
    TestReportWidget *reportView = nullptr;

    void showCurrentQuest();
    void DeleteWidget(QWidget *&&widget);
};

#endif // SIMPLETESTVIEW_H
