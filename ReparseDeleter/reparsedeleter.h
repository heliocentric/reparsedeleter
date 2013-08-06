#ifndef REPARSEDELETER_H
#define REPARSEDELETER_H

#include <QMainWindow>

namespace Ui {
class ReparseDeleter;
}

class ReparseDeleter : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ReparseDeleter(QWidget *parent = 0);
    ~ReparseDeleter();
    
private:
    Ui::ReparseDeleter *ui;
};

#endif // REPARSEDELETER_H
