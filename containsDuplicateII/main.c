#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

int hash(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize <= 1 || k <= 0) return false;

    Node* table[TABLE_SIZE] = {NULL};

    for (int i = 0; i < numsSize; i++) {
        int h = hash(nums[i]);
        Node* curr = table[h];

        while (curr) {
            if (curr->key == nums[i]) {
                if (i - curr->index <= k) {
                    return true;
                } else {
                    curr->index = i;
                    goto continue_loop;
                }
            }
            curr = curr->next;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->index = i;
        newNode->next = table[h];
        table[h] = newNode;

        continue_loop:;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    return false;
}
