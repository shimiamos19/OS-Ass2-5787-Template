
#include <stdio.h>
#include <stdlib.h>

/**
 * Second part of starter code for function address and memory region exploration.
 *
 * Author: Michael J. May
 * Version: 2026
 */

extern double stuff;

/* A recursive function */
int recur(int i, float j, char k) {

    /* Stack allocated variables */
    int localInt = i;
    float localFloat = j;
    char localChar = k;
    double localArr[1024];

    /* Initialize first array element */
    localArr[0] = 0.0;

    void *return_addr = __builtin_return_address(0);

    printf("=== recur() call %d - Return address: %p ===\n", i, return_addr);

    /* Addresses of parameters */
    printf("recursive call %d: parameter int %d @ %p\n",
           i, i, (void *)&i);

    printf("recursive call %d: parameter float %2.2f @ %p\n",
           i, j, (void *)&j);

    printf("recursive call %d: parameter char %c @ %p\n",
           i, k, (void *)&k);

    /* Addresses of local variables */
    printf("recursive call %d: stack int %i @ %p\n",
           i, localInt, (void *)&localInt);

    printf("recursive call %d: stack float %2.2f @ %p\n",
           i, localFloat, (void *)&localFloat);

    printf("recursive call %d: stack char %c @ %p\n",
           i, localChar, (void *)&localChar);

    printf("recursive call %d: stack double[] %2.2f @ %p\n",
           i, localArr[0], (void *)localArr);

    /* Address of static variable */
    printf("static data: stuff %2.2f @ %p\n\n",
           stuff, (void *)&stuff);

    if (i > 0) {
        return recur(i - 1, j - 1.5, k + 1);
    }

    return 0;
}
