#include <stdio.h>
#include "pcaptool.h"

int main(void)
{
    puts("****************open the file!************************");

    char buf[BUF_LEN] = {};
    FILE *pcapFile = fopen("pcap.txt", "r");

    if (NULL == pcapFile)
    {
        return 0;
    }
    char cprt = 'o';
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

    puts("\n****************file has been closed!****************");
    printf("%s", buf);
}

void *readPcapFileToBuf(void *FilePath, void *AcessMode)
{
}