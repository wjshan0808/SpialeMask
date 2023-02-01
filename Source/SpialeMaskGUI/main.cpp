#include "SpialeMaskGUI.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /**/
    CSpialeMaskGUI oSpialeMaskGUI;
    {

        oSpialeMaskGUI.show();
    }

    /**/
    return a.exec();
}
