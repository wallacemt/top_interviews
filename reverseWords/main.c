char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = malloc(sizeof(char) * (len + 1));
    int index = 0;
    int start = len - 1;
    int end = len - 1;
    while (start >= 0) {
        while (start >= 0 && (s[start] == ' ' || s[start] == '\t')) start--;
        end = start;
        while (end >= 0 && s[end] != ' ' && s[end] != '\t') end--;
        if (start >= 0) {
            int wordLen = start - end;
            memcpy(result + index, s + end + 1, wordLen);
            index += wordLen;
            if (end > 0) result[index++] = ' ';
        }
        start = end;
    }
    if (index > 0 && result[index - 1] == ' ') index--;
    result[index] = '\0';
    return result;
}

