struct Node *connect(struct Node *root)
{
    if (root == NULL)
        return NULL;

    struct Node *current = root;
    while (current)
    {
        struct Node *dummy = malloc(sizeof(struct Node));
        dummy->next = NULL; 
        struct Node *temp = dummy;

        while (current)
        {
            if (current->left)
            {
                temp->next = current->left;
                temp = temp->next;
            }
            if (current->right)
            {
                temp->next = current->right;
                temp = temp->next;
            }
            current = current->next;
        }

        current = dummy->next;
        free(dummy);
    }

    return root;
}
