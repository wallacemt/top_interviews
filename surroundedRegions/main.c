
#define MAX_M 200
#define MAX_N 200

void dfs(char** board, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }
    board[i][j] = '#';
    dfs(board, i - 1, j, m, n);
    dfs(board, i + 1, j, m, n);
    dfs(board, i, j - 1, m, n);
    dfs(board, i, j + 1, m, n);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];
    
    for (int i = 0; i < m; i++) {
        dfs(board, i, 0, m, n);
        dfs(board, i, n - 1, m, n);
    }
    
    for (int j = 0; j < n; j++) {
        dfs(board, 0, j, m, n);
        dfs(board, m - 1, j, m, n);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
