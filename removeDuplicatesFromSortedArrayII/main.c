int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            if (count < 2) {
                nums[k++] = nums[i];
                count++;
            }
        } else {
            nums[k++] = nums[i];
            count = 1;
        }
    }
    return k;
}
