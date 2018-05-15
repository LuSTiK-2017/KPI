#include <stdio.h>
#include "validation.h"
#include "recursion.h"

// Culculate of binomial factory with recurtion
int recurtion(int n, int k)
{
    if (k > n/2) k = n - k;
	if (k == 1)  return n;
	if (k == 0)  return 1;
    else
        return recurtion(n - 1, k - 1) + recurtion(n - 1, k);
}

// Input data
void binom_cof()
{
    int n, k;
    long result;
    printf("N = ");
    n = validation_int();
    printf("K = ");
    k = validation_int();

    result = recurtion(n, k);
    printf("Result: %ld", result);
}