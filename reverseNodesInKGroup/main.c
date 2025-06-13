struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = tail->next;
    struct ListNode* curr = head;
    struct ListNode* next;
    while (prev != tail) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return tail;
}
struct ListNode* getKthNode(struct ListNode* head, int k) {
    while (head && k--) head = head->next;
    return head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* ptr = head;
    for (int i = 0; i < k; ++i) {
        if (!ptr) return head;
        ptr = ptr->next;
    }
    struct ListNode* newHead = reverse(head, getKthNode(head, k-1));
    head->next = reverseKGroup(ptr, k);
    return newHead;
}


