void helper(struct TreeNode* root, int cur, int* sum) {
    if (!root->left && !root->right) {
        *sum += cur * 10 + root->val;
        return;
    }
    if (root->left) helper(root->left, cur * 10 + root->val, sum);
    if (root->right) helper(root->right, cur * 10 + root->val, sum);
}
int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    if (!root) return 0;
    helper(root, 0, &sum);
    return sum;
}


