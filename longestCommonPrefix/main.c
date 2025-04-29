char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        minLen = minLen < strlen(strs[i]) ? minLen : strlen(strs[i]);
    }
    
    char* result = malloc(sizeof(char) * (minLen + 1));
    int index = 0;
    for (int i = 0; i < minLen; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (c != strs[j][i]) {
                result[index] = '\0';
                return result;
            }
        }
        result[index++] = c;
    }
    result[index] = '\0';
    return result;
}
