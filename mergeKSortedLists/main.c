#include <stdlib.h>
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    while (listsSize > 1) {
        int i, j;
        for (i = 0, j = 0; j < listsSize; j += 2, i++) {
            if (j + 1 < listsSize) {
                lists[i] = mergeTwoLists(lists[j], lists[j + 1]);
            } else {
                lists[i] = lists[j];
            }
        }
        listsSize = i;
    }
    return lists[0];
}
