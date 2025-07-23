#include <stdlib.h>
void combinationSumUtil(int* candidates, int candidatesSize, int target, int start, int* currentCombination, int currentLength, int*** result, int* resultSize, int** returnColumnSizes) {
    if (target == 0) {
        (*result)[*resultSize] = malloc(sizeof(int) * currentLength);
        for (int i = 0; i < currentLength; i++) {
            (*result)[*resultSize][i] = currentCombination[i];
        }
        (*returnColumnSizes)[*resultSize] = currentLength;
        (*resultSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            currentCombination[currentLength] = candidates[i];
            combinationSumUtil(candidates, candidatesSize, target - candidates[i], i, currentCombination, currentLength + 1, result, resultSize, returnColumnSizes);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 150);
    int** result = malloc(sizeof(int*) * 150);
    int* currentCombination = malloc(sizeof(int) * target);
    combinationSumUtil(candidates, candidatesSize, target, 0, currentCombination, 0, &result, returnSize, returnColumnSizes);
    free(currentCombination);
    return result;
}

