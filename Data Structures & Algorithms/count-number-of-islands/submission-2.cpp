class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            int x = r + dir[i][0];
            int y = c + dir[i][1];

            if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1') {
                dfs(grid, x, y);
            }
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
