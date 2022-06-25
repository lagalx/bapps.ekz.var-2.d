#include <process.h>
#include <stdio.h>
#include <string.h>

#include <QApplication>
#include <QCryptographicHash>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPalette>
#include <QProcess>
#include <QString>

#include "mainwindow.h"

typedef unsigned long long QWORD;

const QString PROTECTOR_PATH = "DebugProtector.exe";
const QByteArray HASH = "wfMfoazt3lGPvsEAclKod42khn5LvHle8gNsEqoQSXE=";

QProcess *startSattelite() {
  if (!QFileInfo::exists(PROTECTOR_PATH)) {
    QMessageBox::critical(
        nullptr, "Error",
        QFileInfo(PROTECTOR_PATH).absoluteFilePath() + " Not Found");
    exit(-1);
  }

  QProcess *satelliteProcess = new QProcess();
  int pid = QApplication::applicationPid();

  QStringList arguments = {QString::number(pid)};
  satelliteProcess->start("DebugProtector.exe", arguments);
  satelliteProcess->waitForStarted(1000);
  return satelliteProcess;
}

int killPD(QProcess *p) {
  p->close();
  return 0;
}

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  auto p = startSattelite();

  return a.exec(), killPD(p);
}
