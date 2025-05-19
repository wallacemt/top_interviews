bool isIsomorphic(char* s, char* t) {
    int len = strlen(s);
    int map[256] = {0};
    for (int i = 0; i < len; i++) {
        if (map[s[i]] == 0) {
            int j;
            for (j = 0; j < 256; j++) {
                if (map[j] == t[i]) break;
            }
            if (j == 256) map[s[i]] = t[i];
            else return false;
        }
        else if (map[s[i]] != t[i]) return false;
    }
    return true;
}
