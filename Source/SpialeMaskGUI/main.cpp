#include "Gui/Gui.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*界面*/
    CGui oGui;
    {
        oGui.Setup(argc, argv);
    }

    /**/
    return a.exec();
}
