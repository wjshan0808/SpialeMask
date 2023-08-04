#include <QCoreApplication>
#include "testLog.cpp"
#include "testCog.cpp"
#include "testCogChain.cpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    if(0x00)
    {
        testCogChain();
    }

    if(0x00)
    {
        testCog();
    }

    if(0x00)
    {
        testLog();
    }

    return a.exec();
}
