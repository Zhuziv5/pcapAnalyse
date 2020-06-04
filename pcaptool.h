#ifndef __PCAPTOOL_H__
#define __PCAPTOOL_H__
#endif

char readPcapFileToBuf(void *FilePath, void *AcessMode);
char getHttpReqHeader(char *pcapReq);
void releaseBuf();

#define VERSION_LENGTH 8
#define REQ_METHOD_LENGTH 8
#define BUF_LEN 1024
#define FAIL 1
#define SUCCESS 0

extern char buf[BUF_LEN];
extern char *method;
#define NULL_POINTER_RTN(POINTER, UNEXCEPTED) \
    do                                        \
    {                                         \
        if (POINTER == UNEXCEPTED)            \
        {                                     \
            return FAIL;                      \
        }                                     \
    } while (0)

typedef struct httpReqHeader
{
    char method[REQ_METHOD_LENGTH];
    char *req_url;
    char http_version[VERSION_LENGTH];
    char *req_host;
    char hasDoubleCrNf; /*双回车换行 carriage return;line feed*/
    char reserve[7];

    char *reqBody; /*请求消息体*/
} httpReqHeader;

typedef struct httpRespHeader
{
    char http_version[VERSION_LENGTH];

    unsigned short status_code;
    char reserve[5];
    char hasDoubleCrNf; /*双回车换行 carriage return;line feed*/

    char *status_code_brief;
    char *respBody; /*响应消息体*/
} httpRespHeader;
