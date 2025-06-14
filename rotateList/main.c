struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (k < 0 || head == NULL) return head;
    int len = 0;
    struct ListNode *curr = head;
    while (curr)
    {
        curr = curr->next;
        len++;
    }
    k %= len;
    if (!k)
        return head;
    curr = head;
    for (int i = 0; i < len - k - 1; i++)
        curr = curr->next;
    struct ListNode *newHead = curr->next;
    curr->next = NULL;
    curr = newHead;
    while (curr->next)
        curr = curr->next;
    curr->next = head;
    return newHead;
}