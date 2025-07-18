#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

typedef struct {
    TrieNode* root;
} WordDictionary;

TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

WordDictionary* wordDictionaryCreate() {
    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    obj->root = createTrieNode();
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    TrieNode* node = obj->root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool searchInNode(TrieNode* node, char* word) {
    for (int i = 0; word[i]; i++) {
        if (word[i] == '.') {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (node->children[j] && searchInNode(node->children[j], word + i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int index = word[i] - 'a';
            if (node->children[index] == NULL) {
                return false;
            }
            node = node->children[index];
        }
    }
    return node->isEndOfWord;
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchInNode(obj->root, word);
}

void freeTrie(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}

void wordDictionaryFree(WordDictionary* obj) {
    freeTrie(obj->root);
    free(obj);
}
