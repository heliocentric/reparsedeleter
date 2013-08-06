#include "reparsedeleter.h"
#include "ui_reparsedeleter.h"
#include <qprocess.h>

ReparseDeleter::ReparseDeleter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReparseDeleter)
{
    ui->setupUi(this);
    /*
    QLinkedList<QDir> dirs;
    dirs << QDir("C:\\Program Files\\Microsoft Security Client");
    dirs << QDir("C:\\Program Files\\Windows Defender");
    ReparseDeleter::DeleteAll(dirs);
    */
}

ReparseDeleter::~ReparseDeleter()
{
    delete ui;
}
void ReparseDeleter::on_btnRun_clicked() {
    QLinkedList<QDir> dirs;
    if (ui->chkSecurityEssentials->isChecked() == true) {
        dirs << QDir("C:\\Program Files\\Microsoft Security Client");
    }
    if (ui->chkDefender->isChecked() == true) {
            dirs << QDir("C:\\Program Files\\Windows Defender");
    }
    if (ui->chkCustom->isChecked() == true) {
        dirs << QDir(ui->lineEdit->text());
    }
    ReparseDeleter::DeleteAll(dirs);
}

void ReparseDeleter::DeleteAll(QLinkedList<QDir> dirs) {
    QStringList sl;
    QLinkedList<QDir>::iterator i = dirs.begin();
    while (i != dirs.end()) {
        QDir dir = *i;
        QStringList entries = dir.entryList();
        for( QStringList::ConstIterator entry=entries.begin(); entry!=entries.end(); ++entry)
        {
            QString file = *entry;
            if (file == ".") {
            } else if(file == "..") {
            } else {
                QStringList args;
                args << "reparsepoint";
                args << "delete";
                QString path = "" + dir.path() + "/" + file + "";
                QString path2 = path.replace(QRegExp("/"),"\\");
                args << path2;
                QProcess process;
                process.start("fsutil", args);
                process.waitForFinished(-1);
                QByteArray ba = process.readAllStandardOutput();
                QString output = ba;
                sl << output;
            }
        }
        i++;
    }
    QMessageBox msgBox;
    msgBox.setText(sl.join("\n"));
    msgBox.exec();
}
