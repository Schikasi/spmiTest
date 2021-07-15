#ifndef SIMPLENAVIGATEVIEW_H
#define SIMPLENAVIGATEVIEW_H

#include <QButtonGroup>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class SimpleNavigateView;
}

class SimpleNavigateView : public QWidget
{
    Q_OBJECT

public:
    enum button{
        next = 0x001,
        prev = 0x002,
        pages = 0x004
    };
    Q_DECLARE_FLAGS(buttons,button)

    explicit SimpleNavigateView(buttons b, int countPages, QWidget *parent = nullptr);
    ~SimpleNavigateView();

signals:
    void PreviousQuestion();
    void ChangeQuestion(int i);
    void NextQuestion();
private:
    Ui::SimpleNavigateView *ui;

    QPushButton* prevPB = nullptr;
    QPushButton* nextPB = nullptr;
    QButtonGroup *pagesG = nullptr;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(SimpleNavigateView::buttons)

#endif // SIMPLENAVIGATEVIEW_H
