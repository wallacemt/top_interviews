#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define INITIAL_CAPACITY 16
#define HASH_SIZE 100003

typedef struct HashNode {
    int key;
    int index;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** table;
} HashMap;

typedef struct {
    int* values;
    int size;
    int capacity;
    HashMap* map;
} RandomizedSet;

/* ------------------- HashMap Functions ------------------- */
unsigned int hash(int key) {
    return ((unsigned int)key % HASH_SIZE);
}

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->table = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    return map;
}

void hashmapPut(HashMap* map, int key, int index) {
    unsigned int h = hash(key);
    HashNode* node = map->table[h];
    while (node) {
        if (node->key == key) {
            node->index = index;
            return;
        }
        node = node->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = map->table[h];
    map->table[h] = newNode;
}

bool hashmapGet(HashMap* map, int key, int* indexOut) {
    unsigned int h = hash(key);
    HashNode* node = map->table[h];
    while (node) {
        if (node->key == key) {
            *indexOut = node->index;
            return true;
        }
        node = node->next;
    }
    return false;
}

bool hashmapRemove(HashMap* map, int key) {
    unsigned int h = hash(key);
    HashNode* node = map->table[h];
    HashNode* prev = NULL;
    while (node) {
        if (node->key == key) {
            if (prev) prev->next = node->next;
            else map->table[h] = node->next;
            free(node);
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = map->table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->table);
    free(map);
}

/* ------------------- RandomizedSet Functions ------------------- */
RandomizedSet* randomizedSetCreate() {
    srand(time(NULL));
    RandomizedSet* set = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    set->capacity = INITIAL_CAPACITY;
    set->size = 0;
    set->values = (int*)malloc(sizeof(int) * set->capacity);
    set->map = createHashMap();
    return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int index;
    if (hashmapGet(obj->map, val, &index)) return false;

    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->values = (int*)realloc(obj->values, sizeof(int) * obj->capacity);
    }

    obj->values[obj->size] = val;
    hashmapPut(obj->map, val, obj->size);
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int index;
    if (!hashmapGet(obj->map, val, &index)) return false;

    int lastVal = obj->values[obj->size - 1];

    obj->values[index] = lastVal;
    hashmapPut(obj->map, lastVal, index);

    obj->size--;
    hashmapRemove(obj->map, val);
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randIndex = rand() % obj->size;
    return obj->values[randIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->values);
    freeHashMap(obj->map);
    free(obj);
}
