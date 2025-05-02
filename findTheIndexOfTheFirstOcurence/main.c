int strStr(char* haystack, char* needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    for (int i = 0; i <= hlen - nlen; i++) {
        int j = 0;
        while (j < nlen && haystack[i + j] == needle[j]) j++;
        if (j == nlen) return i;
    }
    return -1;
}