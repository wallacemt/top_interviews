int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int **result = malloc(sizeof(int *) * (numsSize * (numsSize - 1) / 2));
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (numsSize * (numsSize - 1) / 2));
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = numsSize - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                result[(*returnSize)++] = malloc(sizeof(int) * 3);
                result[*returnSize - 1][0] = nums[i];
                result[*returnSize - 1][1] = nums[left];
                result[*returnSize - 1][2] = nums[right];
                (*returnColumnSizes)[*returnSize - 1] = 3;
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
        }
    }
    return result;
}
