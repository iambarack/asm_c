#include <stdio.h>

int main()
{
    char str[100]; // declaring a character array

    FILE *filePtr; // declaring a file pointer

    filePtr = fopen("test.casm", "r"); // opening the file

    // checking if the file opening was unsuccessful
    if (filePtr == NULL)
    {
        // if yes, print the error message
        printf("Some error occurred, the file was not read");
    }
    else
    {
        // if the file was successfully opened, then

        // reading line by line till we reach the end of the file
        while (fgets(str, 100, filePtr))
        {
            printf("The read string is : %s", str); // printing each line
        }
    }

    fclose(filePtr); // closing the file

    return 0;
}
