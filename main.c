#include <stdio.h>
#include "pcaptool.h"

int main(void)
{
    puts("****************open the file!************************");

    readPcapFileToBuf("pcap.txt", "r");

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
