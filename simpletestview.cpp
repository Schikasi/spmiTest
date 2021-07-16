#include "simpletestview.h"
#include "ui_simpletestview.h"

#include <Widgets/oneofwidget.h>

SimpleTestView::SimpleTestView(BaseTest *test, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleTestView)
{
    if(test == nullptr) throw nullptr; //ОШИБКА!!!!!
    ui->setupUi(this);
    this->test = test;
}

SimpleTestView::~SimpleTestView()
{
    delete ui;
}

void SimpleTestView::ShowPreview()
{
    startTestButton = new QPushButton("Начать тест",this);
    startTestButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    ui->verticalLayout->addWidget(startTestButton);
    ui->verticalLayout->setAlignment(startTestButton,Qt::AlignCenter);
    connect(startTestButton, &QPushButton::clicked,this,&SimpleTestView::StartTest);
}

void SimpleTestView::StartTest()
{
    DeleteWidget(startTestButton);

    completeTestButton = new QPushButton("Завершить тест");
    completeTestButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    ui->verticalLayout->addWidget(completeTestButton);
    ui->verticalLayout->setAlignment(completeTestButton,Qt::AlignRight);
    connect(completeTestButton, &QPushButton::clicked,this,&SimpleTestView::CompleteTest);

    test->Start();

    showCurrentQuest();

    navigateView = new SimpleNavigateView(SimpleNavigateView::prev|SimpleNavigateView::next|SimpleNavigateView::pages,test->GetCountQuests(),this);

    connect(navigateView, &SimpleNavigateView::NextQuestion,
            this,&SimpleTestView::NextQuestion);

    connect(navigateView, &SimpleNavigateView::ChangeQuestion,
            this,&SimpleTestView::SetQuestion);

    connect(navigateView, &SimpleNavigateView::PreviousQuestion,
            this,&SimpleTestView::PreviousQuestion);

//    QHBoxLayout *navigationLayout = new QHBoxLayout(this);
//    nextQuestionButton = new QPushButton("->",this);
//    nextQuestionButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
//    nextQuestionButton->setShortcut(QKeySequence(Qt::Key_Right));
//    connect(nextQuestionButton, &QPushButton::clicked,this,&SimpleTestView::NextQuestion);

//    previousQuestionButton = new QPushButton("<-",this);
//    previousQuestionButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
//    previousQuestionButton->setShortcut(QKeySequence(Qt::Key_Left));
//    connect(previousQuestionButton, &QPushButton::clicked,this,&SimpleTestView::PreviousQuestion);

//    navigationLayout->setAlignment(Qt::AlignCenter);
//    navigationLayout->addWidget(previousQuestionButton);
//    navigationLayout->addWidget(nextQuestionButton);
    ui->verticalLayout->addWidget(navigateView);
    //ui->verticalLayout->addLayout(navigationLayout);

}

void SimpleTestView::PreviousQuestion()
{
    qint16 i = test->CurrentQuestIndex()-1;
    SetQuestion(i);
}

void SimpleTestView::NextQuestion()
{
    qint16 i = test->CurrentQuestIndex()+1;
    SetQuestion(i);
}

void SimpleTestView::SetQuestion(qint16 i){
    if(i < test->GetCountQuests() && i >= 0){
        test->SetCurrentQuest(i);
        showCurrentQuest();
    }
}

void SimpleTestView::CompleteTest()
{
    DeleteWidget(completeTestButton);
    DeleteWidget(questView);
    DeleteWidget(navigateView);
    //DeleteWidget(nextQuestionButton);
    //DeleteWidget(previousQuestionButton);

    test->Complete();

    ShowReport();
}

void SimpleTestView::ShowReport()
{
    reportView = new TestReportWidget();
    reportView->SetReport(test->GetReport());
    reportView->ShowReport();
    ui->verticalLayout->insertWidget(0,reportView);
}

void SimpleTestView::showCurrentQuest()
{
    DeleteWidget(questView);

    const BaseQuest *curQuest = test->CurrentQuest();
    BaseUserAnswer* curUserAns = test->GetCurrentUserAnswer();
    if (curQuest->GetType() == BaseQuest::OneOfAny){
        questView = new OneOfWidget(curQuest,curUserAns,this);
    }
    ui->verticalLayout->insertWidget(1,questView);
}

void SimpleTestView::DeleteWidget(QWidget *&&widget){
    if(widget !=nullptr){
        if(ui->verticalLayout->indexOf(widget) != -1)
            ui->verticalLayout->removeWidget(widget);
        delete widget;
        widget = nullptr;
    }
}
