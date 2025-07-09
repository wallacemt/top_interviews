// 130. Surrounded Regions
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:


// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 984.794/2.3M
// Acceptance Rate
// 43.1%

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
