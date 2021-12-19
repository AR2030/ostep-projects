#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    //  If no files are specifid on the command line.
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int file_i = 1; file_i < argc; file_i++)
    {
        //  open file
        FILE *fp = fopen(argv[file_i], "r");
        if (fp == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        // read an int then read a char
        int count;
        char c;
        while (fread(&count,sizeof(int),1,fp))
        {
            fread(&c,sizeof(char),1,fp);
            while (count--)
            {
                printf("%c",c);
            }
            
        }
        fclose(fp);
    }
    return 0;
}
