int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int maxLen = 0, start = 0;
    int index[128] = {0};

    for (int j = 0; j < len; j++) {
        if (index[s[j]]) {
            start = start > index[s[j]] ? start : index[s[j]];
        }
        maxLen = maxLen > j - start + 1 ? maxLen : j - start + 1;
        index[s[j]] = j + 1;
    }
    return maxLen;
}
