#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(QWidget *parent = nullptr);
    ~ItemWidget();
    void setData(const int number);
    const int showItem();

private:
    Ui::ItemWidget *ui;
    int score = 0;
    bool isShowed = false;
};

#endif // ITEMWIDGET_H
