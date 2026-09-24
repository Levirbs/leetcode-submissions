class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i >= rows || i < 0 || j >= cols || j < 0 || grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        int sum = 0;
        for (int k = 0; k < 4; k++) {
            sum += dfs(grid, i + dir[k][0], j + dir[k][1]);
        }
        
        return 1 + sum;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};
