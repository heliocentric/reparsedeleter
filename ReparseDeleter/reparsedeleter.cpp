#include "reparsedeleter.h"
#include "ui_reparsedeleter.h"
#include <Qdir.h>


ReparseDeleter::ReparseDeleter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReparseDeleter)
{
    ui->setupUi(this);

}

ReparseDeleter::~ReparseDeleter()
{
    delete ui;
}
