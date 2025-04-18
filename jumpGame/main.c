bool canJump(int* nums, int numsSize) {
    int last = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (i + nums[i] >= last) {
            last = i;
        }
    }   
    return last == 0;
}