int minSubArrayLen(int target, int *nums, int numsSize)
{
    int left = 0, right = 0, sum = 0, res = INT_MAX;
    while (right < numsSize)
    {
        sum += nums[right++];
        while (sum >= target)
        {
            res = fmin(res, right - left);
            sum -= nums[left++];
        }
    }
    if (res == INT_MAX)
        return 0;
    else
    {
        return res;
    }
}