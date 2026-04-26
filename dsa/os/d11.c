#include <stdio.h>

int B;  // Shared variable

// P1: C = B-1; B = 2*C;
void P1() {
    int C;
    C = B - 1;
    B = 2 * C;
}

// P2: D = 2*B; B = D-1;
void P2() {
    int D;
    D = 2 * B;
    B = D - 1;
}

int main() {
    int results[10];
    int count = 0;
    int i, j, found;

    printf("Simulating all interleavings manually:\n\n");

    // Case 1: P1 fully then P2
    B = 2;
    { int C; C = B-1; B = 2*C; }   // P1
    { int D; D = 2*B; B = D-1; }   // P2
    printf("Case 1 (P1 -> P2):                        B = %d\n", B);
    results[count++] = B;

    // Case 2: P2 fully then P1
    B = 2;
    { int D; D = 2*B; B = D-1; }   // P2
    { int C; C = B-1; B = 2*C; }   // P1
    printf("Case 2 (P2 -> P1):                        B = %d\n", B);
    results[count++] = B;

    // Case 3: P1 reads, P2 runs fully, P1 writes
    B = 2;
    int C3, D3;
    C3 = B - 1;                     // P1 reads
    { int D; D = 2*B; B = D-1; }   // P2 fully
    B = 2 * C3;                     // P1 writes
    printf("Case 3 (P1 read -> P2 full -> P1 write):  B = %d\n", B);
    results[count++] = B;

    // Case 4: P2 reads, P1 runs fully, P2 writes
    B = 2;
    int C4, D4;
    D4 = 2 * B;                     // P2 reads
    { int C; C = B-1; B = 2*C; }   // P1 fully
    B = D4 - 1;                     // P2 writes
    printf("Case 4 (P2 read -> P1 full -> P2 write):  B = %d\n", B);
    results[count++] = B;

    // Case 5: P1 reads, P2 reads, P1 writes, P2 writes
    B = 2;
    int C5, D5;
    C5 = B - 1;                     // P1 reads
    D5 = 2 * B;                     // P2 reads
    B = 2 * C5;                     // P1 writes
    B = D5 - 1;                     // P2 writes
    printf("Case 5 (P1r -> P2r -> P1w -> P2w):        B = %d\n", B);
    results[count++] = B;

    // Case 6: P2 reads, P1 reads, P2 writes, P1 writes
    B = 2;
    int C6, D6;
    D6 = 2 * B;                     // P2 reads
    C6 = B - 1;                     // P1 reads
    B = D6 - 1;                     // P2 writes
    B = 2 * C6;                     // P1 writes
    printf("Case 6 (P2r -> P1r -> P2w -> P1w):        B = %d\n", B);
    results[count++] = B;

    // Find distinct values
    int distinct[10];
    int dcount = 0;

    for (i = 0; i < count; i++) {
        found = 0;
        for (j = 0; j < dcount; j++) {
            if (distinct[j] == results[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            distinct[dcount++] = results[i];
        }
    }

    printf("\n========================================\n");
    printf("Distinct values B can take: ");
    for (i = 0; i < dcount; i++) {
        printf("%d ", distinct[i]);
    }
    printf("\nTotal distinct values: %d\n", dcount);

    return 0;
}