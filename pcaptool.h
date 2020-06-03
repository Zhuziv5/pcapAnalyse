#ifndef __PCAPTOOL_H__
#define __PCAPTOOL_H__
#endif

char readPcapFileToBuf(void *FilePath, void *AcessMode);

#define BUF_LEN 1024
#define FAIL 1
#define SUCCESS 0

#define NULL_POINTER_RTN(POINTER, UNEXCEPTED) \
    do                                        \
    {                                         \
        if (POINTER == UNEXCEPTED)            \
        {                                     \
            return FAIL;                      \
        }                                     \
    } while (0)
