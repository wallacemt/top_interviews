#include <limits.h>
#include <stdlib.h>


void inOrderTraversal(struct TreeNode* root, int* minDiff, struct TreeNode** prev) {
    if (!root) return;

    inOrderTraversal(root->left, minDiff, prev);

    if (*prev) {
        int diff = abs(root->val - (*prev)->val);
        if (diff < *minDiff) {
            *minDiff = diff;
        }
    }
    *prev = root;

    inOrderTraversal(root->right, minDiff, prev);
}

int getMinimumDifference(struct TreeNode* root) {
    int minDiff = INT_MAX;
    struct TreeNode* prev = NULL;
    inOrderTraversal(root, &minDiff, &prev);
    return minDiff;
}
