#include <stdio.h>

int main()
{
    FILE *fptr;

    // Open file for writing
    fptr = fopen("file-handling.txt", "w+");

    if (fptr == NULL)
    {
        printf("Error in accessing.\n");
    }
    else
    {
        fprintf(fptr, "Writing from the .C program.\n"); // Writing data into the file
        fclose(fptr);                                    // Close the file for writing
    }

    // Reopen file for reading
    fptr = fopen("file-handling.txt", "r");

    if (fptr == NULL)
    {
        printf("Error in accessing.\n");
    }
    else
    {
        char buffer[255]; // Store data file

        // No whitespace characters
        // while (fscanf(fptr, "%s", buffer) != EOF)
        // {
        //     printf("%s", buffer); // Print what is written on the .txt into a .exe
        // }

        // With whitespace characters
        while (fgets(buffer, sizeof(buffer), fptr) != NULL)
        {
            printf("%s", buffer);
        }

        fclose(fptr); // Close the file for reading
    }

    return 0;
}