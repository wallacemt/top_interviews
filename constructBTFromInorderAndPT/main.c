struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (postorderSize == 0) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int index = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == postorder[postorderSize - 1]) {
            index = i;
            break;
        }
    }
    root->left = buildTree(inorder, index, postorder, index);
    root->right = buildTree(inorder + index + 1, inorderSize - index - 1, postorder + index, postorderSize - index - 1);
    return root;
}