#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void wrtie_to_the_file(int seq_len, char c)
{
    fwrite(&seq_len, sizeof(int), 1, stdout);
    fwrite(&c, sizeof(char), 1, stdout);
}
int main(int argc, char const *argv[])
{
    //  If no files are specifid on the command line.
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char current_char;
    char prev_char = '\0';
    int counter = 0;

    for (int file_i = 1; file_i < argc; file_i++)
    {
        //  open file
        FILE *fp = fopen(argv[file_i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        // read a char and count the sequence length.
        while ((current_char = fgetc(fp)))
        {
            
            if (current_char == -1) // end of file
            {
                
                if (file_i == argc - 1) //  last file 
                {
                    wrtie_to_the_file(counter, prev_char);
                }                          
                break;
            }

            if (current_char == prev_char || prev_char == '\0')
            {
                counter++;
                prev_char = current_char;
            }
            else
            {
                wrtie_to_the_file(counter, prev_char);
                prev_char = current_char;
                counter = 1;
            }
        }
        fclose(fp);
    }
    return 0;
}
