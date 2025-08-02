
int maxSubarraySumCircular(int* nums, int numsSize) {
    int maxSum = nums[0], minSum = nums[0], totalSum = nums[0];
    int currentMax = nums[0], currentMin = nums[0];
    for (int i = 1; i < numsSize; i++) {
        currentMax = fmax(nums[i], currentMax + nums[i]);
        maxSum = fmax(maxSum, currentMax);
        currentMin = fmin(nums[i], currentMin + nums[i]);
        minSum = fmin(minSum, currentMin);
        totalSum += nums[i];
    }
    if (maxSum > 0) {
        return fmax(maxSum, totalSum - minSum);
    }
    return maxSum;
}