#include "mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include "gamewindow.h"

#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_loginButton_clicked() {
  const auto PASSWORD = ui->passwordEdit->text();
  const auto GOOD_PASSWORD = "123456";

  if (PASSWORD == GOOD_PASSWORD) {
    auto nextWindow = new GameWindow();
    nextWindow->show();
    this->close();

    return;
  }

  QMessageBox::warning(this, "Login", "Wrong password");
}

void MainWindow::on_passwordEdit_textChanged(const QString &text) {
  if (text.length() > 4)
    ui->loginButton->setEnabled(true);
  else
    ui->loginButton->setEnabled(false);
}
