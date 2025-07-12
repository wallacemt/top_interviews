struct queue {
    int *data;
    int front;
    int back;
    int size;
    int capacity;
};

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    struct queue q;
    q.capacity = numCourses;
    q.data = malloc(sizeof(int) * q.capacity);
    q.front = 0;
    q.back = 0;
    q.size = 0;

    int *indegree = calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        indegree[prerequisites[i][0]]++;
    }

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.data[q.back++] = i;
            q.size++;
        }
    }

    int count = 0;
    while (q.size > 0) {
        int cur = q.data[q.front++];
        q.size--;
        count++;
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == cur) {
                indegree[prerequisites[i][0]]--;
                if (indegree[prerequisites[i][0]] == 0) {
                    q.data[q.back++] = prerequisites[i][0];
                    q.size++;
                }
            }
        }
    }
    return count == numCourses;
} 
