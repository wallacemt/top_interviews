int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;
    while (i >= 0 && s[i] == ' ') i--;
    int count = 0;
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}
