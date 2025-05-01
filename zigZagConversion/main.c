char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) return s;

    char* res = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int cycleLen = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            res[index++] = s[i + j];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) 
                res[index++] = s[j + cycleLen - i];
        }
    }
    res[index] = '\0';
    return res;
    
}
