#include <QCoreApplication>
#include "testLog.cpp"
#include "testString.cpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    if(0x01)
    {
        testString();
    }

    if(0x00)
    {
        testLog();
    }

    return a.exec();
}
