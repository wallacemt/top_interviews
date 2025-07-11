#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 1000
#define HASH_SIZE 2001

typedef struct Node {
    char* key;
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* data[HASH_SIZE];
} HashMap;

unsigned hash(char* str) {
    unsigned h = 0;
    while (*str) {
        h = (h * 31 + *str++) % HASH_SIZE;
    }
    return h;
}

HashMap* createMap() {
    HashMap* map = (HashMap*)calloc(1, sizeof(HashMap));
    if (!map) exit(1);
    return map;
}

int mapGet(HashMap* map, char* key, int* out) {
    unsigned h = hash(key);
    Node* node = map->data[h];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            *out = node->val;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void mapPut(HashMap* map, char* key, int val) {
    unsigned h = hash(key);
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) exit(1);
    node->key = strdup(key);
    node->val = val;
    node->next = map->data[h];
    map->data[h] = node;
}

int parent[MAX_VARS];
double weight[MAX_VARS];

int find(int x) {
    if (parent[x] != x) {
        int orig = parent[x];
        parent[x] = find(parent[x]);
        weight[x] *= weight[orig];
    }
    return parent[x];
}

void unionNodes(int x, int y, double value) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
    }
}

double* calcEquation(char*** equations, int equationsSize,
                     int* equationsColSize, double* values, int valuesSize,
                     char*** queries, int queriesSize, int* queriesColSize,
                     int* returnSize) {

    HashMap* map = createMap();
    int nextId = 0;

    for (int i = 0; i < MAX_VARS; i++) {
        parent[i] = i;
        weight[i] = 1.0;
    }

    for (int i = 0; i < equationsSize; i++) {
        char* A = equations[i][0];
        char* B = equations[i][1];
        double val = values[i];

        int idA, idB;
        if (!mapGet(map, A, &idA)) {
            idA = nextId++;
            mapPut(map, A, idA);
        }
        if (!mapGet(map, B, &idB)) {
            idB = nextId++;
            mapPut(map, B, idB);
        }

        unionNodes(idA, idB, val);
    }

    double* result = (double*)malloc(sizeof(double) * queriesSize);
    if (!result) exit(1);
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        char* X = queries[i][0];
        char* Y = queries[i][1];

        int idX, idY;
        int foundX = mapGet(map, X, &idX);
        int foundY = mapGet(map, Y, &idY);

        if (!foundX || !foundY) {
            result[i] = -1.0;
        } else {
            int rootX = find(idX);
            int rootY = find(idY);
            if (rootX != rootY) {
                result[i] = -1.0;
            } else {
                result[i] = weight[idX] / weight[idY];
            }
        }
    }

    return result;
}
