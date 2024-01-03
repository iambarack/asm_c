#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "include/mem_conf.h"

#include "include/tests/stack.test.h"

int main(int argc, char* argv[]) {
    int i;
    //printf("1gb = %lld \n", (long long)64*gigabyte);
    // for (int j = 0; j < argc; j++)
    //     printf("%s\n", argv[j]);
    // printf("%s", argv[1]);

    if(argc < 2) return -1;
    char str[64]; // declaring a character array

    FILE *fptr; // declaring a file pointer
    fptr = fopen(argv[1], "r"); // opening the file

    if (fptr == NULL)
    {
        printf("file read error");
    }
    else
    {
        while (fgets(str, 64, fptr))
        {
            printf("The read string is : %s", str); // printing each line
            for (int i = 0; i < 64; i++)
            {
                if (str[i] == (char)10)
                    break; // 10->EOL
                else
                    printf(" %dx", str[i]); // 32->Space
            }
            printf("\n");
            // while (fgets(str, 64, fptr))
            // {
            //     printf("The read string is : %s", str); // printing each line
            //     for (int i = 0; i < 64; i++)
            //     {
            //         if(str[i] == (char) 10) break; //10->EOL
            //         else printf(" %dx", str[i]);    //32->Space
            //     }
            //     printf("\n");
            // BINARY tree or Binary Search Keywords -/. if push, ifeq or jump expect 1 else 0 if not true eval return 0;
            // USE Fgetc instead for future uses 10 0 16 nweline
        }
    }

    fclose(fptr); // closing the file

    stackTest();

    return 0;
}