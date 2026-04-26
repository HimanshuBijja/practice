# Process Synchronization — Concurrent Execution of P1 and P2

---

## 1. Problem Statement

Two functions **P1** and **P2** share a common variable **B** with an initial value of **2**.
Both functions execute **concurrently** (at the same time).

**Find the number of distinct values that B can possibly take after concurrent execution.**

---

## 2. The Two Processes

### P1()
```c
void P1() {
    int C;
    C = B - 1;   // Step 1: Read B, compute C
    B = 2 * C;   // Step 2: Write result back to B
}
```
- `C` is a **local variable** (private to P1)
- Reads global `B`, subtracts 1, stores in `C`
- Then writes `2 * C` back to global `B`

---

### P2()
```c
void P2() {
    int D;
    D = 2 * B;   // Step 1: Read B, compute D
    B = D - 1;   // Step 2: Write result back to B
}
```
- `D` is a **local variable** (private to P2)
- Reads global `B`, multiplies by 2, stores in `D`
- Then writes `D - 1` back to global `B`

---

## 3. Key Concept — What is Interleaving?

Since P1 and P2 run **concurrently**, their individual read and write operations
can mix up in different orders. This mixing is called **Interleaving**.

Each process has **2 atomic steps**:

| Process | Step 1 | Step 2 |
|---------|--------|--------|
| P1 | C = B - 1 (Read) | B = 2 * C (Write) |
| P2 | D = 2 * B (Read) | B = D - 1 (Write) |

These **4 steps** can be arranged in **6 different possible orders**.

---

## 4. All 6 Interleaving Cases

### Case 1 — P1 runs fully, then P2 runs fully
```
B = 2
P1: C = 2-1 = 1,  B = 2*1 = 2
P2: D = 2*2 = 4,  B = 4-1 = 3
Result: B = 3
```

---

### Case 2 — P2 runs fully, then P1 runs fully
```
B = 2
P2: D = 2*2 = 4,  B = 4-1 = 3
P1: C = 3-1 = 2,  B = 2*2 = 4
Result: B = 4
```

---

### Case 3 — P1 reads, P2 runs fully, P1 writes
```
B = 2
P1 reads:  C = 2-1 = 1       (B is still 2)
P2 fully:  D = 2*2 = 4, B = 3
P1 writes: B = 2*1 = 2       (P2's result is overwritten!)
Result: B = 2
```

---

### Case 4 — P2 reads, P1 runs fully, P2 writes
```
B = 2
P2 reads:  D = 2*2 = 4       (B is still 2)
P1 fully:  C = 2-1 = 1, B = 2
P2 writes: B = 4-1 = 3       (P1's result is overwritten!)
Result: B = 3
```

---

### Case 5 — Both read, P1 writes, then P2 writes
```
B = 2
P1 reads: C = 2-1 = 1
P2 reads: D = 2*2 = 4
P1 writes: B = 2*1 = 2
P2 writes: B = 4-1 = 3       (Last write wins)
Result: B = 3
```

---

### Case 6 — Both read, P2 writes, then P1 writes
```
B = 2
P2 reads: D = 2*2 = 4
P1 reads: C = 2-1 = 1
P2 writes: B = 4-1 = 3
P1 writes: B = 2*1 = 2       (Last write wins)
Result: B = 2
```

---

## 5. Summary Table

| Case | Execution Order | Final Value of B |
|------|----------------|-----------------|
| 1 | P1 full → P2 full | 3 |
| 2 | P2 full → P1 full | 4 |
| 3 | P1 read → P2 full → P1 write | 2 |
| 4 | P2 read → P1 full → P2 write | 3 |
| 5 | Both read → P1 write → P2 write | 3 |
| 6 | Both read → P2 write → P1 write | 2 |

---

## 6. The C Program

```c
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
    { int C; C = B-1; B = 2*C; }
    { int D; D = 2*B; B = D-1; }
    printf("Case 1 (P1 -> P2):                        B = %d\n", B);
    results[count++] = B;

    // Case 2: P2 fully then P1
    B = 2;
    { int D; D = 2*B; B = D-1; }
    { int C; C = B-1; B = 2*C; }
    printf("Case 2 (P2 -> P1):                        B = %d\n", B);
    results[count++] = B;

    // Case 3: P1 reads, P2 runs fully, P1 writes
    B = 2;
    int C3; C3 = B - 1;
    { int D; D = 2*B; B = D-1; }
    B = 2 * C3;
    printf("Case 3 (P1 read -> P2 full -> P1 write):  B = %d\n", B);
    results[count++] = B;

    // Case 4: P2 reads, P1 runs fully, P2 writes
    B = 2;
    int D4; D4 = 2 * B;
    { int C; C = B-1; B = 2*C; }
    B = D4 - 1;
    printf("Case 4 (P2 read -> P1 full -> P2 write):  B = %d\n", B);
    results[count++] = B;

    // Case 5: P1 reads, P2 reads, P1 writes, P2 writes
    B = 2;
    int C5, D5;
    C5 = B - 1; D5 = 2 * B;
    B = 2 * C5; B = D5 - 1;
    printf("Case 5 (P1r -> P2r -> P1w -> P2w):        B = %d\n", B);
    results[count++] = B;

    // Case 6: P2 reads, P1 reads, P2 writes, P1 writes
    B = 2;
    int C6, D6;
    D6 = 2 * B; C6 = B - 1;
    B = D6 - 1; B = 2 * C6;
    printf("Case 6 (P2r -> P1r -> P2w -> P1w):        B = %d\n", B);
    results[count++] = B;

    // Find distinct values
    int distinct[10];
    int dcount = 0;
    for (i = 0; i < count; i++) {
        found = 0;
        for (j = 0; j < dcount; j++) {
            if (distinct[j] == results[i]) { found = 1; break; }
        }
        if (!found) distinct[dcount++] = results[i];
    }

    printf("\n========================================\n");
    printf("Distinct values B can take: ");
    for (i = 0; i < dcount; i++) printf("%d ", distinct[i]);
    printf("\nTotal distinct values: %d\n", dcount);

    return 0;
}
```

---

## 7. Program Output

```
Simulating all interleavings manually:

Case 1 (P1 -> P2):                        B = 3
Case 2 (P2 -> P1):                        B = 4
Case 3 (P1 read -> P2 full -> P1 write):  B = 2
Case 4 (P2 read -> P1 full -> P2 write):  B = 3
Case 5 (P1r -> P2r -> P1w -> P2w):        B = 3
Case 6 (P2r -> P1r -> P2w -> P1w):        B = 2

========================================
Distinct values B can take: 3 4 2
Total distinct values: 3
```

---

## 8. Explaination

> **"This program is based on Process Synchronization in Operating Systems."**

- We have two processes P1 and P2 sharing variable B (initial value = 2)
- Since they run **concurrently**, their read/write steps can mix in 6 different orders
- Each order (interleaving) gives a different final value of B
- After checking all 6 cases, B can be **2, 3, or 4**
- This is a classic example of a **Race Condition**
- The final answer is **3 distinct values**

---

## 9. Conclusion

This program demonstrates the concept of **Race Condition** in concurrent processes.
When two processes share a variable without synchronization, the final result depends
on the order of execution. This is why Operating Systems use mechanisms like
**Mutex Locks** and **Semaphores** to control access to shared variables and ensure
correct and consistent results.

---

**Total Distinct Values of B = 3 → { 2, 3, 4 }**