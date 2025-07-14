void getCoordinates(int square, int n, int* row, int* col) {
    int quot = (square - 1) / n;
    int rem = (square - 1) % n;
    *row = n - 1 - quot;
    if (quot % 2 == 0) {
        *col = rem;
    } else {
        *col = n - 1 - rem;
    }
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int* visited = (int*)calloc(n * n + 1, sizeof(int));
    int* queue = (int*)malloc((n * n + 1) * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = 1;
    visited[1] = 1;

    while (front < rear) {
        int cur = queue[front++];
        if (cur == n * n) {
            int result = visited[cur] - 1;
            free(queue);
            free(visited);
            return result;
        }

        for (int i = 1; i <= 6 && cur + i <= n * n; i++) {
            int next = cur + i;
            int row, col;
            getCoordinates(next, n, &row, &col);
            if (board[row][col] != -1) {
                next = board[row][col];
            }
            if (!visited[next]) {
                visited[next] = visited[cur] + 1;
                queue[rear++] = next;
            }
        }
    }

    free(queue);
    free(visited);
    return -1;
}
