void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int m = boardSize, n = boardColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;

            for (int d = 0; d < 8; d++) {
                int ni = i + directions[d][0], nj = j + directions[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && abs(board[ni][nj]) == 1) {
                    liveNeighbors++;
                }
            }

            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                board[i][j] = -1;
            }
            if (board[i][j] == 0 && liveNeighbors == 3) {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}
