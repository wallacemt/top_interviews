#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    char* word; 
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = calloc(1, sizeof(TrieNode));
    return node;
}
void insertWord(TrieNode* root, char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!node->children[idx]) {
            node->children[idx] = createNode();
        }
        node = node->children[idx];
    }
    node->word = strdup(word);  
}
void freeTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(node->children[i]);
    }
    if (node->word) free(node->word);
    free(node);
}
int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void dfs(char** board, int m, int n, int i, int j, TrieNode* node, bool** visited, char*** result, int* returnSize) {
    char c = board[i][j];
    int idx = c - 'a';

    if (!node->children[idx]) return;

    node = node->children[idx];
    if (node->word) {
        *result = realloc(*result, sizeof(char*) * (*returnSize + 1));
        (*result)[*returnSize] = strdup(node->word);
        (*returnSize)++;

        free(node->word);  
        node->word = NULL;
    }

    visited[i][j] = true;

    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0], nj = j + dirs[d][1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
            dfs(board, m, n, ni, nj, node, visited, result, returnSize);
        }
    }

    visited[i][j] = false;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    int m = boardSize, n = boardColSize[0];
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(root, words[i]);
    }
    bool** visited = malloc(sizeof(bool*) * m);
    for (int i = 0; i < m; i++) {
        visited[i] = calloc(n, sizeof(bool));
    }

    char** result = NULL;
    *returnSize = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(board, m, n, i, j, root, visited, &result, returnSize);
        }
    }
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
    freeTrie(root);

    return result;
}
