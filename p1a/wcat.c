#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    //  If no files are specifid on the command line.
    if (argc == 1)
    {
        exit(0);
    }

    
    for (size_t file_i = 1; file_i < argc; file_i++)
    {
        //  open file
        FILE *fp = fopen(argv[file_i], "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        // read a line and write it to the standard output.
        char *line = NULL;
        size_t len = 0;
        size_t nread;
        while ((nread = getline(&line, &len, fp)) != -1)
        {
           fwrite(line, nread, 1, stdout); 
        }
    }

    return 0;
}
