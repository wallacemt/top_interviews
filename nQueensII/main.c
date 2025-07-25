#include <string.h>
void backtrack(int* board, int n, int row, int* res) {
    if (row == n) {
        (*res)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        bool valid = true;
        for (int i = 0; i < row; i++) {
            if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
                valid = false;
                break;
            }
        }
        if (valid) {
            board[row] = col;
            backtrack(board, n, row + 1, res);
        }
    }
}
int totalNQueens(int n) {
    int res = 0;
    int* board = malloc(sizeof(int) * n * n);
    memset(board, 0, sizeof(int) * n * n);
    backtrack(board, n, 0, &res);
    free(board);
    return res;
}

