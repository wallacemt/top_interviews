#include <stdlib.h>
#include <stdio.h>

#define HASH_SIZE 10009  

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct HashNode {
    int key;
    Node *node;
    struct HashNode *next;
} HashNode;

typedef struct {
    int capacity, size;
    Node *head, *tail;
    HashNode* hash[HASH_SIZE];
} LRUCache;

int hashFunc(int key) {
    return key % HASH_SIZE;
}

Node* hashGet(LRUCache* obj, int key) {
    int index = hashFunc(key);
    HashNode *entry = obj->hash[index];
    while (entry) {
        if (entry->key == key)
            return entry->node;
        entry = entry->next;
    }
    return NULL;
}

void hashPut(LRUCache* obj, int key, Node* node) {
    int index = hashFunc(key);
    HashNode *entry = (HashNode*)malloc(sizeof(HashNode));
    entry->key = key;
    entry->node = node;
    entry->next = obj->hash[index];
    obj->hash[index] = entry;
}

void hashRemove(LRUCache* obj, int key) {
    int index = hashFunc(key);
    HashNode **entry = &obj->hash[index];
    while (*entry) {
        if ((*entry)->key == key) {
            HashNode *temp = *entry;
            *entry = (*entry)->next;
            free(temp);
            return;
        }
        entry = &((*entry)->next);
    }
}

void moveToHead(LRUCache* obj, Node* node) {
    if (obj->head == node) return;

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (obj->tail == node) obj->tail = node->prev;

    node->prev = NULL;
    node->next = obj->head;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;
}

void removeTail(LRUCache* obj) {
    if (!obj->tail) return;
    hashRemove(obj, obj->tail->key);
    Node *prev = obj->tail->prev;
    free(obj->tail);
    obj->tail = prev;
    if (prev) prev->next = NULL;
    else obj->head = NULL;
    obj->size--;
}
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = obj->tail = NULL;
    for (int i = 0; i < HASH_SIZE; i++)
        obj->hash[i] = NULL;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = hashGet(obj, key);
    if (!node) return -1;
    moveToHead(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = hashGet(obj, key);
    if (node) {
        node->value = value;
        moveToHead(obj, node);
    } else {
        if (obj->size == obj->capacity)
            removeTail(obj);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->prev = newNode->next = NULL;
        newNode->next = obj->head;
        if (obj->head) obj->head->prev = newNode;
        obj->head = newNode;
        if (!obj->tail) obj->tail = newNode;
        hashPut(obj, key, newNode);
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *entry = obj->hash[i];
        while (entry) {
            HashNode *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(obj);
}

