int evalRPN(char** tokens, int tokensSize) {
    int* stack = malloc(sizeof(int) * tokensSize);
    int top = 0;
    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0) {
            int b = stack[--top];
            int a = stack[--top];
            stack[top++] = a + b;
        } else if (strcmp(tokens[i], "-") == 0) {
            int b = stack[--top];
            int a = stack[--top];
            stack[top++] = a - b;
        } else if (strcmp(tokens[i], "*") == 0) {
            int b = stack[--top];
            int a = stack[--top];
            stack[top++] = a * b;
        } else if (strcmp(tokens[i], "/") == 0) {
            int b = stack[--top];
            int a = stack[--top];
            stack[top++] = a / b;
        } else {
            stack[top++] = atoi(tokens[i]);
        }
    }
    int result = stack[top - 1];
    free(stack);
    return result;
}

