#include <limits.h>


int maxPathSumUtil(struct TreeNode* root, int* result) {
    if (root == NULL) return 0;

    int left = fmax(0, maxPathSumUtil(root->left, result));
    int right = fmax(0, maxPathSumUtil(root->right, result));

    *result = fmax(*result, left + right + root->val);

    return root->val + fmax(left, right);
}

int maxPathSum(struct TreeNode* root) {
    int result = INT_MIN;
    maxPathSumUtil(root, &result);
    return result;
}
