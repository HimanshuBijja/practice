// C program to demonstrate Byte Stuffing

#include <stdio.h>
#include <string.h>

#define FLAG 'F'
#define ESC 'E'

void byteStuffing(char *input, char *output)
{
    int i = 0, j = 0;

    // Add starting FLAG
    output[j++] = FLAG;

    // Process each character in input
    while (input[i] != '\0')
    {
        // If character is FLAG or ESC, add ESC before it
        if (input[i] == FLAG || input[i] == ESC)
        {
            output[j++] = ESC;
        }
        output[j++] = input[i++];
    }

    // Add ending FLAG
    output[j++] = FLAG;
    output[j] = '\0';
}

void byteDestuffing(char *input, char *output)
{
    int i = 1, j = 0; // Start from 1 to skip starting FLAG
    int len = strlen(input);

    // Process until the ending FLAG
    while (i < len - 1)
    {
        // If ESC is found, skip it and copy next character
        if (input[i] == ESC)
        {
            i++;
        }
        output[j++] = input[i++];
    }
    output[j] = '\0';
}

int main()
{
    char input[100], stuffed[200], destuffed[100];

    printf("Enter data to be transmitted: ");
    scanf("%s", input);

    // Perform byte stuffing
    byteStuffing(input, stuffed);
    printf("\nAfter Byte Stuffing: %s\n", stuffed);

    // Perform byte destuffing
    byteDestuffing(stuffed, destuffed);
    printf("After Byte Destuffing: %s\n", destuffed);

    // Verify if original and destuffed are same
    if (strcmp(input, destuffed) == 0)
    {
        printf("\nData transmitted successfully!\n");
    }
    else
    {
        printf("\nError in transmission!\n");
    }

    return 0;
}
