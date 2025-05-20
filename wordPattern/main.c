bool wordPattern(char* pattern, char* s) {
    char *word = strtok(s, " ");
    int i = 0;
    char *map[256] = {NULL};

    while (word != NULL) {
        if (pattern[i] == '\0') return false;

        if (map[(unsigned char)pattern[i]] == NULL) {
            for (int j = 0; j < 256; j++) {
                if (map[j] != NULL && strcmp(map[j], word) == 0) return false;
            }
            map[(unsigned char)pattern[i]] = word;
        } else if (strcmp(map[(unsigned char)pattern[i]], word) != 0) {
            return false;
        }

        word = strtok(NULL, " ");
        i++;
    }

    return pattern[i] == '\0';
}

