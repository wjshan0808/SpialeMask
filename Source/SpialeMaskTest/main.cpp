#include <QCoreApplication>

#include "testLog.cpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(0x01)
    {
        testLog();
    }

    return a.exec();
}
