
#include "pcaptool.h"

int main(void)
{
    puts("****************open the pcapReq.txt file!************************");

    readPcapFileToBuf("pcapReq.txt", "r");
    // printf("%s\n", buf);
    unsigned int index = 0;
    char *reqLine, *reqMethod;
    index = getHttpHeaderFirstLine(buf);
    // printf("reqline length is %d\n", index);
    reqLine = (char *)copyBufToHttpFirstLine(index);
    reqMethod = findFieldInString(reqLine, method, sizeof(*method));
    if (NULL == reqMethod)
    {
        puts("Request doesn't have method!");
        return 0;
    }
    // printf("reqline string is %s\n", reqLine);
    printf("reqMethod is %s\n", reqMethod);
    // puts("****************read the pcapReq.txt file!************************");

    puts("****************open the pcapResp.txt file!************************");
    readPcapFileToBuf("pcapResp.txt", "r");
    unsigned int respIndex = 0;
    char *respLine, *respStatusCode;
    respIndex = getHttpHeaderFirstLine(buf);
    // printf("respLine length is %d\n", respIndex);
    respLine = copyBufToHttpFirstLine(respIndex);
    respStatusCode = findFieldInString(respLine, statusCode, sizeof(*statusCode));
    if (NULL == respStatusCode)
    {
        puts("Request doesn't have statusCode!");
        return 0;
    }
    // printf("respLine string is %s\n", respLine);
    printf("Status Code is %s\n", respStatusCode);
    // puts("****************read the pcapResp.txt file!************************");
}
