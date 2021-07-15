#include "oneofwidget.h"
#include "ui_oneofwidget.h"

#include "simpleanswer.h"

#include <QButtonGroup>
#include <QButtonGroup>


OneOfWidget::OneOfWidget(const BaseQuest *quest, BaseUserAnswer *userAns, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OneOfWidget)
{
    if (quest == nullptr) throw nullptr;// ОШИБКА!!!
    if (userAns == nullptr) throw nullptr;// ОШИБКА!!!

    ui->setupUi(this);
    buttonGroup = new QButtonGroup(this);
    SetUserAnswer(userAns);
    SetQuest(quest);
}

OneOfWidget::~OneOfWidget()
{
    delete ui;
}

void OneOfWidget::SetQuest(const BaseQuest *quest)
{
    this->question = dynamic_cast<const SimpleQuest *>(quest);
    if(question == nullptr) throw nullptr; //ОШИБКА!!!!!!!!

    ui->textBrowser->insertPlainText(question->GetText());
    for(int i = 0; i < question->GetCountAnswers(); ++i){
        const BaseAnswer *ans = question->GetAnswer(i);
        QPushButton * pushButton = new QPushButton(this);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setText(ans->GetText());
        pushButton->setCheckable(true);
        pushButton->setChecked(ans == userAnswer->GetSelectedAnswer());
        pushButton->setAutoExclusive(true);
        pushButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        ui->verticalLayout->addWidget(pushButton,Qt::AlignCenter);
        answers.append(pushButton);
        buttonGroup->addButton(pushButton,i);
    }
    connect(buttonGroup,&QButtonGroup::idClicked,
            this,&OneOfWidget::UpdateUserAnswer);
}
void OneOfWidget::UpdateUserAnswer(int id){
    userAnswer->SetSelectedAnswer(dynamic_cast<const SimpleAnswer *>(question->GetAnswer(id)));
}

void OneOfWidget::SetUserAnswer(BaseUserAnswer *userAns)
{
    this->userAnswer = dynamic_cast<SimpleUserAnswer *>(userAns);
    if(userAnswer == nullptr) throw nullptr; //ОШИБКА!!!!!!!!
}
