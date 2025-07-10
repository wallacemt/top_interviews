#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* cloneNode(struct Node* node, struct Node** clonedNodes) {
    if (clonedNodes[node->val - 1]) {
        return clonedNodes[node->val - 1];
    }
    
    struct Node* clone = malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = malloc(sizeof(struct Node*) * node->numNeighbors);
    clonedNodes[node->val - 1] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneNode(node->neighbors[i], clonedNodes);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;
    struct Node* clonedNodes[100];
    memset(clonedNodes, 0, sizeof(clonedNodes));

    return cloneNode(s, clonedNodes);
}

