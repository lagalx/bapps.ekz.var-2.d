#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QListWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void addItemInList(const int number);
    const static int randomBetween(int low,int high);
    void reset();

public slots:
    void onListItemClicked(QListWidgetItem* item);

private:
    Ui::GameWindow *ui;
    uint clickedAmount = 0;
    int score=0;

    uint itemAmount = 12;
};

#endif // GAMEWINDOW_H
