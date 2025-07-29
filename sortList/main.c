struct ListNode* getMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow->next;
    slow->next = NULL;
    return mid;
}
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    while (left && right) {
        if (left->val < right->val) {
            curr->next = left;
            left = left->next;
        } else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }
    curr->next = left ? left : right;
    return dummy.next;
}
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    struct ListNode* mid = getMiddle(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    return merge(left, right);
}
