class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());      
    }
    Node* helper(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) {
            return new Node(grid[x][y] == 1, true);
        }

        int val = grid[x][y];
        bool isLeaf = true;

        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }

        if (isLeaf) {
            return new Node(val == 1, true);
        } else {
            Node* topLeft = helper(grid, x, y, size / 2);
            Node* topRight = helper(grid, x, y + size / 2, size / 2);
            Node* bottomLeft = helper(grid, x + size / 2, y, size / 2);
            Node* bottomRight = helper(grid, x + size / 2, y + size / 2, size / 2);
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};