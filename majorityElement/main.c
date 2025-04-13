int majorityElement(int* nums, int numsSize) {
    int major = nums[0], count = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == major) count++;
        else count--;
        if(count == 0){
            major = nums[i];
            count = 1;
        }
    }
    return major;
}