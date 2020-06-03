#include <stdio.h>
#include "pcaptool.h"

int main(void)
{
    puts("****************open the file!************************");

    readPcapFileToBuf("pcap.txt", "r");

    puts("****************read the file!************************");
}
