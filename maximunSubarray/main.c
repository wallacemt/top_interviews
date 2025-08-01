int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        current_sum = (current_sum > 0) ? current_sum + nums[i] : nums[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}