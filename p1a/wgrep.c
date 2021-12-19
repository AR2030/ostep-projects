#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    FILE *fp;
    
    if (argc == 1)  //  If no searchterm and file are specifid on the command line.
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if (argc == 2) //  If no file specifid the read from stdin.
    {
        fp = stdin;
    }
    else //  open file
    {
        fp = fopen(argv[2], "r");
        if (fp == NULL)
        {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    }

    char *line = NULL;
    size_t len = 0;
    size_t nread;
    while ((nread = getline(&line, &len, fp)) != -1)
    {
        if (strstr(line, argv[1]) != NULL)
        {
            fwrite(line, nread, 1, stdout);
        }
    }

    return 0;
}
