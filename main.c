
#include "pcaptool.h"

int main(void)
{
    puts("****************open the file!************************");

    readPcapFileToBuf("pcapReq.txt", "r");
    // printf("%s\n", buf);
    unsigned int index = 0;
    char *reqLine, *reqMethod;
    index = getRequestLine(buf);
    printf("reqline length is %d\n", index);
    reqLine = (char *)copyBufToReqline(index);
    reqMethod = findFieldInString(reqLine, method, sizeof(*method));
    if (NULL == reqMethod)
    {
        puts("Request doesn't have method!");
        return 0;
    }
    printf("reqline string is %s\n", reqLine);
    puts("****************read the file!************************");
}
