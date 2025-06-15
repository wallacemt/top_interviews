struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode dummy1, dummy2;
    struct ListNode* left = &dummy1, *right = &dummy2;
    while (head) {
        struct ListNode* next = head->next;
        if (head->val < x) {
            left->next = head;
            left = left->next;
        } else {
            right->next = head;
            right = right->next;
        }
        head = next;
    }
    left->next = dummy2.next;
    right->next = NULL;
    return dummy1.next;
}
