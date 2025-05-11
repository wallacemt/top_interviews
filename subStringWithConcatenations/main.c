int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    if (wordsSize == 0 || strlen(s) == 0) {
        *returnSize = 0;
        return (int*)malloc(sizeof(int));
    }
    
    int wordLength = strlen(words[0]);
    int totalWordsLength = wordsSize * wordLength;
    int count[26] = {0};
    
    for (int i = 0; i < wordsSize; i++) {
        count[tolower(words[i][0]) - 'a']++;
    }
    
    int *result = (int*)malloc(sizeof(int) * (strlen(s) - totalWordsLength + 1));
    *returnSize = 0;
    
    for (int i = 0; i <= strlen(s) - totalWordsLength; i++) {
        int temp[26] = {0};
        int j;
        for (j = 0; j < wordsSize; j++) {
            int k = i + j * wordLength;
            if (k >= strlen(s) || (s[k] < 'a' || s[k] > 'z') || count[tolower(s[k]) - 'a'] == 0) break;
            temp[tolower(s[k]) - 'a']++;
            if (temp[tolower(s[k]) - 'a'] > count[tolower(s[k]) - 'a']) break;
        }
        if (j == wordsSize) {
            result[(*returnSize)++] = i;
            i += wordLength - 1;
        }
    }
    
    return result;
}

