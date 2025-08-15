char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = fmax(lenA, lenB);
    char* result = (char*)malloc(maxLen + 2);
    result[maxLen + 1] = '\0';

    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int bitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
        int bitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
        int sum = bitA + bitB + carry;
        result[maxLen - i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[0] = carry + '0';
    if (result[0] == '0') {
        memmove(result, result + 1, maxLen + 1);
    }
    return result;
}