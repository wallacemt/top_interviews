#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int* returnSize) {
    if (!digits || !*digits) {
        *returnSize = 0;
        return NULL;
    }

    char* mapping[] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    int digitsLength = strlen(digits);
    int totalCombinations = 1;
    for (int i = 0; i < digitsLength; i++) {
        totalCombinations *= strlen(mapping[digits[i] - '0']);
    }

    char** result = malloc(totalCombinations * sizeof(char*));
    *returnSize = 0;
    char* combination = malloc(digitsLength + 1);
    combination[digitsLength] = '\0';

    void backtrack(int index) {
        if (index == digitsLength) {
            result[(*returnSize)++] = strdup(combination);
            return;
        }
        char* letters = mapping[digits[index] - '0'];
        for (int i = 0; letters[i]; i++) {
            combination[index] = letters[i];
            backtrack(index + 1);
        }
    }

    backtrack(0);
    free(combination);
    return result;
}
