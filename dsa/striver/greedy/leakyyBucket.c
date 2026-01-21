// C program to implement Leaky Bucket Algorithm

#include <stdio.h>

int main() {
    int bucketSize, outputRate, inputPackets, currentBucket = 0;
    int n, i;
    
    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);
    
    printf("Enter output rate (packets/time): ");
    scanf("%d", &outputRate);
    
    printf("Enter number of time slots: ");
    scanf("%d", &n);
    
    printf("\nEnter incoming packets for each time slot:\n");
    
    for (i = 1; i <= n; i++) {
        printf("Time slot %d: ", i);
        scanf("%d", &inputPackets);
        
        printf("\n--- Time Slot %d ---\n", i);
        printf("Incoming packets: %d\n", inputPackets);
        printf("Bucket before: %d\n", currentBucket);
        
        // Add incoming packets to bucket
        if (currentBucket + inputPackets <= bucketSize) {
            currentBucket += inputPackets;
            printf("All packets accepted\n");
        } else {
            int dropped = (currentBucket + inputPackets) - bucketSize;
            currentBucket = bucketSize;
            printf("Bucket overflow! %d packet(s) dropped\n", dropped);
        }
        
        // Send packets at output rate
        if (currentBucket >= outputRate) {
            currentBucket -= outputRate;
            printf("Packets sent: %d\n", outputRate);
        } else if (currentBucket > 0) {
            printf("Packets sent: %d\n", currentBucket);
            currentBucket = 0;
        } else {
            printf("Packets sent: 0\n");
        }
        
        printf("Bucket after: %d\n\n", currentBucket);
    }
    
    // Handle remaining packets in bucket
    if (currentBucket > 0) {
        printf("--- Draining remaining packets ---\n");
        int time = i;
        while (currentBucket > 0) {
            printf("Time slot %d:\n", time);
            if (currentBucket >= outputRate) {
                currentBucket -= outputRate;
                printf("Packets sent: %d\n", outputRate);
            } else {
                printf("Packets sent: %d\n", currentBucket);
                currentBucket = 0;
            }
            printf("Bucket after: %d\n\n", currentBucket);
            time++;
        }
    }
    
    printf("All packets processed. Bucket is now empty.\n");
    
    return 0;
}
