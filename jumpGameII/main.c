int jump(int* nums, int numsSize) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}
