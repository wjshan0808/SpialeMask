#include <QCoreApplication>
#include "testLog.cpp"
#include "testCog.cpp"
#include "testCogChain.cpp"
#include "testRoulette.cpp"
#include "testRouletteChain.cpp"
#include "testSpiale.cpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    while (true)
    {
        if(0x00)
        {
            testRouletteChain();
        }

        if(0x00)
        {
            testRoulette();
        }

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

    }

    return a.exec();
}
