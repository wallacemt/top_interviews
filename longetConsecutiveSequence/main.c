#include <stdlib.h>
#include <stdbool.h>

bool exists(int *table, int num) {
    return table[(num + 1000000)] != 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int *hashTable = calloc(2000001, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        hashTable[(nums[i] + 1000000)] = 1;
    }
    
    int longest = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (!exists(hashTable, nums[i] - 1)) {
            int currentNum = nums[i];
            int currentStreak = 0;
            
            while (exists(hashTable, currentNum)) {
                currentStreak++;
                currentNum++;
            }
            
            longest = longest > currentStreak ? longest : currentStreak;
        }
    }
    
    free(hashTable);
    return longest;
}

