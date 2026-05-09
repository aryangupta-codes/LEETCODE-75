#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    double current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    
    double max_sum = current_sum;
    
    for (int i = k; i < numsSize; i++) {
        current_sum += nums[i] - nums[i - k];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum / k;
}

int main() {
    int nums[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    double result = findMaxAverage(nums, numsSize, k);
    printf("%f\n", result);

    return 0;
}