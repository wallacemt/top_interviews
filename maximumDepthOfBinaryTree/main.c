int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}