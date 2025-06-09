#include <stdlib.h>
struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    struct Node* curr = head;
    while (curr) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        newNode->random = NULL;
        curr->next = newNode;
        curr = newNode->next;
    }
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    curr = head;
    struct Node* pseudoHead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* copyCurr = pseudoHead;
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        copyCurr->next = copy;
        copyCurr = copy;
        curr = curr->next;
    }
    struct Node* result = pseudoHead->next;
    free(pseudoHead);
    return result;
}
