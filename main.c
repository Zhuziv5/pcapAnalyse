#include <stdio.h>
#include "pcaptool.h"

char buf[BUF_LEN] = {};
int main(void)
{
    puts("****************open the file!************************");

    readPcapFileToBuf("pcap.txt", "r");

    puts("****************read the file!************************");
}

char readPcapFileToBuf(void *filePath, void *accessMode)
{
    FILE *pcapFile = fopen(filePath, accessMode);
    NULL_POINTER_RTN(pcapFile, NULL);
    char cprt = '0';
    unsigned int i = 0;
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
    return SUCCESS;
}