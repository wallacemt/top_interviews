
bool isSymmetric(struct TreeNode *root)
{
    return isMirror(root, root);
}

bool isMirror(struct TreeNode *left, struct TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
