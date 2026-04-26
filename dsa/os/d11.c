#include <stdio.h>
#include <string.h>

#define MAX 20

int finalValues[MAX];
int finalCount = 0;

void executeSequence(char result[][10], int total) {
    int B = 2;
    int C = 0, D = 0;

    printf("\nExecution Order: ");

    for(int i = 0; i < total; i++) {
        printf("%s ", result[i]);
    }

    printf("\n");

    for(int i = 0; i < total; i++) {

        if(strcmp(result[i], "P1a") == 0) {
            C = B - 1;
            printf("P1a -> C = %d\n", C);
        }

        else if(strcmp(result[i], "P1b") == 0) {
            B = 2 * C;
            printf("P1b -> B = %d\n", B);
        }

        else if(strcmp(result[i], "P2a") == 0) {
            D = 2 * B;
            printf("P2a -> D = %d\n", D);
        }

        else if(strcmp(result[i], "P2b") == 0) {
            B = D - 1;
            printf("P2b -> B = %d\n", B);
        }
    }

    printf("Final B = %d\n", B);

    // store distinct values
    int found = 0;
    for(int i=0;i<finalCount;i++) {
        if(finalValues[i] == B) {
            found = 1;
            break;
        }
    }

    if(!found) {
        finalValues[finalCount++] = B;
    }
}

void generateInterleavings(
    char p1[][10], int n1, int i,
    char p2[][10], int n2, int j,
    char result[][10], int k
) {
    if(i == n1 && j == n2) {
        executeSequence(result, k);
        return;
    }

    if(i < n1) {
        strcpy(result[k], p1[i]);
        generateInterleavings(p1, n1, i+1, p2, n2, j, result, k+1);
    }

    if(j < n2) {
        strcpy(result[k], p2[j]);
        generateInterleavings(p1, n1, i, p2, n2, j+1, result, k+1);
    }
}

int main() {

    char p1[][10] = {"P1a", "P1b"};
    char p2[][10] = {"P2a", "P2b"};

    int n1 = 2;
    int n2 = 2;

    char result[MAX][10];

    generateInterleavings(p1, n1, 0, p2, n2, 0, result, 0);

    printf("\nDistinct Final Values: ");
    for(int i=0;i<finalCount;i++) {
        printf("%d ", finalValues[i]);
    }

    printf("\nNumber of distinct values = %d\n", finalCount);

    return 0;
}