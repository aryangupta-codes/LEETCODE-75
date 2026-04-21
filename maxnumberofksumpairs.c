#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int maxOperations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int ops = 0;
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        long current_sum = (long)nums[left] + nums[right];
        
        if (current_sum == k) {
            ops++;
            left++;
            right--;
        } else if (current_sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    return ops;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int k = 5;
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = maxOperations(nums, size, k);
    printf("Max Operations: %d\n", result);
    
    return 0;
}