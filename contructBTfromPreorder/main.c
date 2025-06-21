
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int index = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            index = i;
            break;
        }
    }
    root->left = buildTree(preorder + 1, index, inorder, index);
    root->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, inorderSize - index - 1);
    return root;   
}