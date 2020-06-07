#include "pcaptool.h"

char buf[BUF_LEN] = {0};
char *method[] = {"get ", "put ", "head ", "post ", "delete ",
                  "connect ", "trace "};
char *statusCode[] = {"200 ", "404 ", "304 ", "302 ", "403 ",
                      "500 ", "502 "};
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
        // printf("%c", cprt);
    }
    fclose(pcapFile);
    // printf("%s", buf);
    // releaseBuf();
    return SUCCESS;
}

void releaseBuf()
{
    memset(buf, 0, BUF_LEN);
}
