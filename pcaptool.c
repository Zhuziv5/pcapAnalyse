#include <stdio.h>
#include <string.h>
#include "pcaptool.h"

char buf[BUF_LEN] = {};

char readPcapFileToBuf(void *filePath, void *accessMode)
{
    FILE *pcapFile = fopen(filePath, accessMode);
    NULL_POINTER_RTN(pcapFile, NULL);
    char cprt = '0';
    unsigned int i = 0;
    releaseBuf();
    while (1)
    {
        cprt = fgetc(pcapFile);
        if (feof(pcapFile))
        {
            break;
        }
        buf[i++] = cprt;
        printf("%c", cprt);
    }
    fclose(pcapFile);
    printf("%s", buf);
    releaseBuf();
    return SUCCESS;
}

void releaseBuf()
{
    memset(buf, 0, BUF_LEN);
}