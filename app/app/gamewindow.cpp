#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "itemwidget.h"
#include <QListWidgetItem>
#include <qglobal.h>
#include <QMessageBox>

const int GameWindow::randomBetween(int low, int high)
{
    // Random number between low and high
    return rand() % ((high + 1) - low) + low;
}

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    ui->scoreLabel->setText(QString::number(score));

    connect(ui->itemListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onListItemClicked(QListWidgetItem*)));

    for (auto i=0;i<itemAmount;i++) {
       const auto number = randomBetween(0,9999);
       this->addItemInList(number);
     }
}



void GameWindow::addItemInList(const int number) {
  auto listItemW = new QListWidgetItem();
  auto itemW = new ItemWidget(this);

  itemW->setData(number);
  listItemW->setSizeHint(itemW->sizeHint());

  ui->itemListWidget->addItem(listItemW);
  ui->itemListWidget->setItemWidget(listItemW, itemW);


}

void GameWindow::onListItemClicked(QListWidgetItem* item)
{

    auto itemWidget = dynamic_cast<ItemWidget*>(
           ui->itemListWidget->itemWidget(item));
    auto selectedScore = itemWidget->showItem();
    if (selectedScore!=0){
        clickedAmount++;
        score += selectedScore;
        ui->scoreLabel->setText(QString::number(score));
    }
    if (clickedAmount==4){
        QMessageBox::information(this, "Score", QString::number(score));

        reset();
    }

}
void GameWindow::reset(){
    ui->itemListWidget->clear();
    for (auto i=0;i<itemAmount;i++) {
       const auto number = randomBetween(0,9999);
       this->addItemInList(number);
     }
    clickedAmount=0;
    score=0;
    ui->scoreLabel->setText(QString::number(score));
}

GameWindow::~GameWindow()
{
    delete ui;
}
