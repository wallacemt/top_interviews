void rightSideViewUtil(struct TreeNode* root, int *result, int *returnSize, int level) {
    if (!root) return;
    if (*returnSize == level) {
        result[(*returnSize)++] = root->val;
    }
    rightSideViewUtil(root->right, result, returnSize, level + 1);
    rightSideViewUtil(root->left, result, returnSize, level + 1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *result = malloc(sizeof(int) * 101);
    *returnSize = 0;
    rightSideViewUtil(root, result, returnSize, 0);
    return result;
}
