typedef struct {
    struct TreeNode* stack[10001];
    int top;

} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = -1;
    while (root) {
        obj->stack[++obj->top] = root;
        root = root->left;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[obj->top--];
    int val = node->val;
    node = node->right;
    while (node) {
        obj->stack[++obj->top] = node;
        node = node->left;
    }
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) { return obj->top != -1; }

void bSTIteratorFree(BSTIterator* obj) { free(obj); }

