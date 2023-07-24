
#include <QDebug>
#include "SpialeMask.h"

#include <string.h>
#include <stdlib.h>


void testString()
{
    char arr[0x04] = { "" };
    arr[0x00] = ' ';
    qDebug("arr = %d", qstrnlen(arr,4));


}
