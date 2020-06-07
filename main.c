
#include "pcaptool.h"

int main(void)
{
    puts("****************open the file!************************");

    readPcapFileToBuf("pcapReq.txt", "r");
    // printf("%s\n", buf);
    unsigned int index = 0;
    char *reqLine;
    index = getRequestLine(buf);
    printf("reqline is %d\n", index);
    reqLine = (char *)copyBufToReqline(index);
    printf("reqline is %s\n", reqLine);

    findSubstring(buf, "get");
    char index = 7;
    index = getHttpReqHeader(buf);
    if (index > 6)
    {
        puts("Pcapfile doesn't have request method!");
    }
    else
    {
        printf("Method of request line is %s\n", method[index]);
    }
    puts("****************read the file!************************");
}
