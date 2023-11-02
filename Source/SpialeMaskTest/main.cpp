#include <QCoreApplication>
#include "testLog.cpp"
#include "testCog.cpp"
#include "testCogChain.cpp"
#include "testRoulette.cpp"
#include "testRouletteChain.cpp"
#include "testSpiale.cpp"
//include "testAssemble.cpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //while (true)
    {


        //if(0x00)
        {
            testSpialeAPI();
        }

        if(0x00)
        {
            testRouletteChainAPI();
        }

        if(0x00)
        {
            testRouletteAPI();
        }

        if(0x00)
        {
            testCogChainAPI();
        }

        if(0x00)
        {
            testCogAPI();
        }


        if(0x00)
        {
            testLog();
        }

    }

    return a.exec();
}
