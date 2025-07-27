bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = *boardColSize;
    int wordLen = strlen(word);
    bool dfs(int r, int c, int index) {
        if (index == wordLen) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) return false;
        
        char temp = board[r][c]; 
        board[r][c] = '#'; 
        bool found = dfs(r + 1, c, index + 1) ||
                     dfs(r - 1, c, index + 1) ||
                     dfs(r, c + 1, index + 1) ||
                     dfs(r, c - 1, index + 1);
        
        board[r][c] = temp; 
        return found;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0] && dfs(i, j, 0)) {
                return true; 
            }
        }
    }
    
    return false; 
}