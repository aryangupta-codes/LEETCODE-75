#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        int current_height = height[left] < height[right] ? height[left] : height[right];
        int current_water = width * current_height;

        if (current_water > max_water) {
            max_water = current_water;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    
    int result = maxArea(height, size);
    
    printf("Max area: %d\n", result);
    
    return 0;
}