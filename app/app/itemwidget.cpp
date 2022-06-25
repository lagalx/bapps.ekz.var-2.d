#include "itemwidget.h"
#include "ui_itemwidget.h"

ItemWidget::ItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
    ui->numberLabel->setVisible(true);
}

ItemWidget::~ItemWidget()
{
    delete ui;
}

void ItemWidget::setData(const int number) {
  score = number;
}


const int ItemWidget::showItem(){
    if(!isShowed){
        ui->numberLabel->setText(QString::number(score));
        isShowed = true;

        return score;
    }
    return 0;
}

