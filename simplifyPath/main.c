char* simplifyPath(char* path) {
    char* result = malloc(sizeof(char) * 3000);
    int index = 0;
    char* token = strtok(path, "/");
    char* stack[3000];
    int top = -1;
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top >= 0) top--;
        } else if (strcmp(token, ".") != 0 && strcmp(token, "") != 0) {
            stack[++top] = token;
        }
        token = strtok(NULL, "/");
    }
    for (int i = 0; i <= top; i++) {
        result[index++] = '/';
        strcpy(result + index, stack[i]);
        index += strlen(stack[i]);
    }
    if (index > 0 && result[index - 1] == '/') index--;
    result[index] = '\0';
    if (index == 0) {
        result[index++] = '/';
        result[index] = '\0';
    }
    return result;
}

