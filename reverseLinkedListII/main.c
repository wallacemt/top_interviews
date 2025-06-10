struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right) return head;
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    for (int i = 0; i < left - 1; i++) prev = prev->next;
    struct ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy->next;   
}