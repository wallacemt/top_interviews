void backtrack(int* nums, int numsSize, int start, int** result, int* returnSize, int** returnColumnSizes) {
    if (start == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = nums[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        int temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;

        backtrack(nums, numsSize, start + 1, result, returnSize, returnColumnSizes);
        temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 2; i <= numsSize; i++) total *= i;

    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, result, returnSize, returnColumnSizes);
    return result;
}
