
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    int* result = malloc(sizeof(int) * 2);
    int left = 0, right = numbersSize - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }

    }   
    
    return result;
}