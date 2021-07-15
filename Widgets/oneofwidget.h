#ifndef ONEOFWIDGET_H
#define ONEOFWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <simpleanswer.h>

#include <QButtonGroup>
#include "simpleuseranswer.h"
#include <simplequest.h>

namespace Ui {
class OneOfWidget;
}

class OneOfWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OneOfWidget(const BaseQuest* quest,BaseUserAnswer* userAns, QWidget *parent = nullptr);
    ~OneOfWidget();

    void UpdateUserAnswer(int id);
private:
    Ui::OneOfWidget *ui;
    const SimpleQuest *question = nullptr;
    SimpleUserAnswer *userAnswer = nullptr;
    QVector<QPushButton *> answers;
    QButtonGroup *buttonGroup = nullptr;
    void SelectUserAnswer();
    void SetQuest(const BaseQuest* quest);
    void SetUserAnswer(BaseUserAnswer *userAns);
};

#endif // ONEOFWIDGET_H
