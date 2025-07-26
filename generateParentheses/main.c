void generateAllCombinations(char*** result, int* returnSize, int open, int close, int n, char* current, int currentIndex, int* capacity) {
    if (open == n && close == n) {
        current[currentIndex] = '\0';
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, sizeof(char*) * (*capacity));
        }
        (*result)[(*returnSize)++] = strdup(current);
        return;
    }

    if (open < n) {
        current[currentIndex] = '(';
        generateAllCombinations(result, returnSize, open + 1, close, n, current, currentIndex + 1, capacity);
    }
    if (close < open) {
        current[currentIndex] = ')';
        generateAllCombinations(result, returnSize, open, close + 1, n, current, currentIndex + 1, capacity);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** result = malloc(sizeof(char*) * 1000);
    int capacity = 1000;
    *returnSize = 0;
    char* current = malloc(sizeof(char) * (2 * n + 1));
    generateAllCombinations(&result, returnSize, 0, 0, n, current, 0, &capacity);
    free(current);
    return result;
}

