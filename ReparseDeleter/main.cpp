#include "reparsedeleter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReparseDeleter w;
    w.show();
    
    return a.exec();
}
