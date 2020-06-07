#include "pcaptool.h"

char buf[BUF_LEN] = {0};
char *method[] = {"get ", "put ", "head ", "post ", "delete ",
                  "connect ", "trace "};
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
    // releaseBuf();
    return SUCCESS;
}

void releaseBuf()
{
    memset(buf, 0, BUF_LEN);
}

char getHttpReqHeader(char *pcapReq)
{
    if (NULL == pcapReq)
    {
        return -1;
    }
    unsigned char i = 0;
    //TODO--处理一下输入的请求行，方法有可能是大写的
    while (i < 7)
    {
        if (0 <= strcmp(pcapReq, method[i]))
        {
            break;
        }
        i++;
    }
    return i;
}
