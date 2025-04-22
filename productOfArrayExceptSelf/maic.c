int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    int productLeft = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = productLeft;
        productLeft *= nums[i];
    }
    int productRight = 1;
    for (int i = numsSize - 1; i > 0; i--) {
        result[i] *= productRight;
        productRight *= nums[i];
    }   
    result[0] *= productRight;
    *returnSize = numsSize;
    return result;
}

