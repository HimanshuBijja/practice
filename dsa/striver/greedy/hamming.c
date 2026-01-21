// C program to implement Hamming Code for error detection and correction

#include <stdio.h>
#include <math.h>

int main()
{
    int data[20], code[20], syndrome[20];
    int n, m, r, i, j, k, temp, error_pos = 0;

    printf("Enter number of data bits: ");
    scanf("%d", &m);

    // Calculate number of redundant bits (r)
    // 2^r >= m + r + 1
    r = 0;
    while (pow(2, r) < m + r + 1)
    {
        r++;
    }

    printf("Number of redundant bits: %d\n", r);
    n = m + r; // Total bits in codeword

    printf("Enter %d data bits: ", m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &data[i]);
    }

    // Initialize code array
    for (i = 0; i < n; i++)
    {
        code[i] = 0;
    }

    // Place data bits in appropriate positions (skip power of 2 positions)
    j = 0;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) == (int)pow(2, k))
        {
            k++;
        }
        else
        {
            code[i] = data[j];
            j++;
        }
    }

    // Calculate parity bits
    for (i = 0; i < r; i++)
    {
        int pos = (int)pow(2, i) - 1; // Position of parity bit (0-indexed)
        int parity = 0;

        for (j = 0; j < n; j++)
        {
            // Check if this position should be included in parity calculation
            if (((j + 1) & (pos + 1)) != 0)
            {
                parity ^= code[j];
            }
        }
        code[pos] = parity;
    }

    printf("\nGenerated Hamming Code: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");

    // Simulate transmission - allow user to introduce error
    printf("\nEnter received code (introduce error if needed): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &code[i]);
    }

    // Calculate syndrome to detect error
    for (i = 0; i < r; i++)
    {
        syndrome[i] = 0;
    }

    for (i = 0; i < r; i++)
    {
        int pos = (int)pow(2, i) - 1;
        int parity = 0;

        for (j = 0; j < n; j++)
        {
            if (((j + 1) & (pos + 1)) != 0)
            {
                parity ^= code[j];
            }
        }
        syndrome[i] = parity;
    }

    // Calculate error position
    error_pos = 0;
    for (i = 0; i < r; i++)
    {
        error_pos += syndrome[i] * (int)pow(2, i);
    }

    if (error_pos == 0)
    {
        printf("\nNo error detected!\n");
    }
    else
    {
        printf("\nError detected at position: %d\n", error_pos);
        printf("Correcting the error...\n");

        // Correct the error
        code[error_pos - 1] = !code[error_pos - 1];

        printf("Corrected code: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", code[i]);
        }
        printf("\n");
    }

    // Extract original data
    printf("\nOriginal data bits: ");
    k = 0;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) != (int)pow(2, k))
        {
            printf("%d ", code[i]);
        }
        else
        {
            k++;
        }
    }
    printf("\n");

    return 0;
}
