double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    long long levelSize = 1;
    struct TreeNode** level = malloc(sizeof(struct TreeNode*));
    level[0] = root;
    long long sum = root->val;
    double* result = malloc(sizeof(double));

    *returnSize = 1;
    result[0] = (double)sum / levelSize;

    while (levelSize > 0) {
        sum = 0;
        long long nextLevelSize = 0;
        struct TreeNode** nextLevel = malloc(sizeof(struct TreeNode*) * levelSize * 2);

        for (int i = 0; i < levelSize; i++) {
            if (level[i]->left) {
                nextLevel[nextLevelSize++] = level[i]->left;
                sum += level[i]->left->val;
            }
            if (level[i]->right) {
                nextLevel[nextLevelSize++] = level[i]->right;
                sum += level[i]->right->val;
            }
        }

        free(level);

        if (nextLevelSize > 0) {
            result = realloc(result, (*returnSize + 1) * sizeof(double));
            result[(*returnSize)++] = (double)sum / nextLevelSize;
        }

        levelSize = nextLevelSize;
        level = nextLevel;
    }

    free(level);

    return result;
}

