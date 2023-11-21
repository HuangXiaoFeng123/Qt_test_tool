#include "toolwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolWidget w;
    w.show();
    return a.exec();
}
