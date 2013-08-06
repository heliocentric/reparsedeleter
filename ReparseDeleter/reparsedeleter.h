#ifndef REPARSEDELETER_H
#define REPARSEDELETER_H

#include <qmainwindow.h>
#include <qlinkedlist.h>
#include <qapplication.h>
#include <qdir.h>
#include <iostream>
#include <qmessagebox.h>
namespace Ui {
class ReparseDeleter;
}

class ReparseDeleter : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ReparseDeleter(QWidget *parent = 0);
    ~ReparseDeleter();
    void DeleteAll(QLinkedList<QDir>);
    
private:
    Ui::ReparseDeleter *ui;
};

#endif // REPARSEDELETER_H
