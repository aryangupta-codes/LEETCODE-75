#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }

    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = 5;
    int extraCandies = 3;
    int returnSize;

    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%s", result[i] ? "true" : "false");
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");

    free(result);
    return 0;
}