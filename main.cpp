#include "qtzooclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtZooClient w;
    w.show();

    return a.exec();
}
