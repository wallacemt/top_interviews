#include <stdlib.h>


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    
    if (numsSize == 0) {
        return result;
    }

    int findFirst(int* nums, int numsSize, int target) {
        int left = 0, right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target || (mid > 0 && nums[mid - 1] == target)) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int findLast(int* nums, int numsSize, int target) {
        int left = 0, right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target || (mid < numsSize - 1 && nums[mid + 1] == target)) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    return result;
}
