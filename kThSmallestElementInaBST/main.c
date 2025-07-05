void kthSmallestUtil(struct TreeNode* root, int k, int* count, int* result) {
    if (!root) return;
    kthSmallestUtil(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    kthSmallestUtil(root->right, k, count, result);
}
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = 0;
    kthSmallestUtil(root, k, &count, &result);
    return result;      
}