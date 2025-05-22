#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define HASH_SIZE 10007 

typedef struct Node {
    char* sortedKey;
    char** group;
    int groupSize;
    int capacity;
    struct Node* next;
} Node;

char* getSortedKey(const char* str) {
    char* key = strdup(str);
    int len = strlen(key);
    qsort(key, len, sizeof(char), (int (*)(const void*, const void*))strcmp);
    return key;
}

unsigned int hashFunc(const char* str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++;
    }
    return hash % HASH_SIZE;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node* hashTable[HASH_SIZE] = {0};
    int groupCount = 0;

    for (int i = 0; i < strsSize; ++i) {
        char* key = getSortedKey(strs[i]);
        unsigned int hash = hashFunc(key);

        Node* node = hashTable[hash];
        while (node) {
            if (strcmp(node->sortedKey, key) == 0) break;
            node = node->next;
        }

        if (!node) {
            node = (Node*)malloc(sizeof(Node));
            node->sortedKey = key;
            node->groupSize = 0;
            node->capacity = 8;
            node->group = (char**)malloc(sizeof(char*) * node->capacity);
            node->next = hashTable[hash];
            hashTable[hash] = node;
            groupCount++;
        } else {
            free(key);
        }

        if (node->groupSize >= node->capacity) {
            node->capacity *= 2;
            node->group = (char**)realloc(node->group, sizeof(char*) * node->capacity);
        }

        node->group[node->groupSize++] = strs[i];
    }

    char*** result = (char***)malloc(sizeof(char**) * groupCount);
    *returnColumnSizes = (int*)malloc(sizeof(int) * groupCount);
    *returnSize = groupCount;

    int idx = 0;
    for (int i = 0; i < HASH_SIZE; ++i) {
        Node* node = hashTable[i];
        while (node) {
            result[idx] = (char**)malloc(sizeof(char*) * node->groupSize);
            for (int j = 0; j < node->groupSize; ++j) {
                result[idx][j] = node->group[j];
            }
            (*returnColumnSizes)[idx] = node->groupSize;
            idx++;

            Node* temp = node;
            node = node->next;
            free(temp->group);
            free(temp->sortedKey);
            free(temp);
        }
    }

    return result;
}
