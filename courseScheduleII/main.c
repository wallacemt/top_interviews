#include <stdlib.h>
#include <stdbool.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* result = (int*)malloc(numCourses * sizeof(int));
    int* degrees = (int*)malloc(numCourses * sizeof(int));
    int** edges = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        degrees[i] = 0;
        edges[i] = (int*)malloc(numCourses * sizeof(int));
        for (int j = 0; j < numCourses; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        degrees[prerequisites[i][0]]++;
        edges[prerequisites[i][1]][prerequisites[i][0]] = 1;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (degrees[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front < rear) {
        int cur = queue[front++];
        result[count++] = cur;
        for (int i = 0; i < numCourses; i++) {
            if (edges[cur][i] == 1) {
                degrees[i]--;
                if (degrees[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    free(degrees);
    for (int i = 0; i < numCourses; i++) {
        free(edges[i]);
    }
    free(edges);
    free(queue);

    if (count != numCourses) {
        free(result);
        *returnSize = 0;
        return NULL;
    }
    *returnSize = count;
    return result;
}
