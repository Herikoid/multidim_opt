#include "chooseparams.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChooseParams w;
    w.show();
    return a.exec();
}
