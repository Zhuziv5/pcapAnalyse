#include <stdio.h>

int main(void)
{
    puts("****************open the file!************************");

    FILE *pcapFile = fopen("pcap.txt", "r");

    char cprt = 'o';
    while (1)
    {
        cprt = fgetc(pcapFile);
        if (feof(pcapFile))
        {
            break;
        }
        printf("%c", cprt);
    }

    fclose(pcapFile);
    puts("\n****************file has been closed!****************");
}