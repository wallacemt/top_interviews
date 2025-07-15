#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValidMutation(char* gene1, char* gene2) {
    int diff = 0;
    for (int i = 0; gene1[i] != '\0' && gene2[i] != '\0'; i++) {
        if (gene1[i] != gene2[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    if (startGene == NULL || endGene == NULL || bank == NULL) return -1;
    if (strcmp(startGene, endGene) == 0) return 0;

    bool* visited = calloc(bankSize, sizeof(bool));
    int queueSize = 1;
    int mutations = 0;
    char** queue = malloc((bankSize + 1) * sizeof(char*));
    queue[0] = startGene;

    while (queueSize > 0) {
        int currentSize = queueSize;
        queueSize = 0;
        mutations++;

        for (int i = 0; i < currentSize; i++) {
            char* currentGene = queue[i];
            for (int j = 0; j < bankSize; j++) {
                if (!visited[j] && isValidMutation(currentGene, bank[j])) {
                    if (strcmp(bank[j], endGene) == 0) {
                        free(queue);
                        free(visited);
                        return mutations;
                    }
                    visited[j] = true;
                    queue[queueSize++] = bank[j];
                }
            }
        }
    }
    free(queue);
    free(visited);
    return -1;
}

