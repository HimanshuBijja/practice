// C program to demonstrate Bit Stuffing

#include <stdio.h>
#include <string.h>

void bitStuffing(char *input, char *output)
{
    int count = 0;
    int i = 0, j = 0;

    // Add FLAG pattern (01111110) at the beginning
    strcpy(output, "01111110");
    j = 8;

    // Process each bit in input
    while (input[i] != '\0')
    {
        output[j++] = input[i];

        // Count consecutive 1's
        if (input[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }

        // After five consecutive 1's, insert a 0
        if (count == 5)
        {
            output[j++] = '0';
            count = 0;
        }
        i++;
    }

    // Add FLAG pattern (01111110) at the end
    strcpy(&output[j], "01111110");
}

void bitDestuffing(char *input, char *output)
{
    int count = 0;
    int i = 8, j = 0; // Start from index 8 to skip starting FLAG
    int len = strlen(input);

    // Process until the ending FLAG (last 8 bits)
    while (i < len - 8)
    {
        output[j++] = input[i];

        // Count consecutive 1's
        if (input[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }

        // After five consecutive 1's, skip the next 0 (stuffed bit)
        if (count == 5)
        {
            i++; // Skip the stuffed 0
            count = 0;
        }
        i++;
    }
    output[j] = '\0';
}

int main()
{
    char input[100], stuffed[200], destuffed[100];

    printf("Enter binary data (only 0s and 1s): ");
    scanf("%s", input);

    // Validate input
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("Error: Please enter only binary digits (0 and 1)\n");
            return 1;
        }
    }

    // Perform bit stuffing
    bitStuffing(input, stuffed);
    printf("\nOriginal Data:        %s\n", input);
    printf("After Bit Stuffing:   %s\n", stuffed);

    // Perform bit destuffing
    bitDestuffing(stuffed, destuffed);
    printf("After Bit Destuffing: %s\n", destuffed);

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
