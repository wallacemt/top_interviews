bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;

    int arr[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) return false;
    }

    return true;
}
