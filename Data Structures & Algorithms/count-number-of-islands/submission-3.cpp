class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') return;

        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dir[i][0], c + dir[i][1]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};
