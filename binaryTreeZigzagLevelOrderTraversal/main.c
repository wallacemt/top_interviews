int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 1000;
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    *returnSize = 0;

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int flag = 0;

    while (front < rear) {
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = realloc(result, sizeof(int*) * capacity);
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
        }

        int levelSize = rear - front;
        result[*returnSize] = malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][flag ? levelSize - 1 - i : i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        (*returnSize)++;
        flag = !flag;
    }

    return result;
}

