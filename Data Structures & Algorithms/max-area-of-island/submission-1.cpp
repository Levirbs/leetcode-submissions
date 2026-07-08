class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        int sum = 1;
        for (int i = 0; i < 4; i++) {
            sum += dfs(grid, r + dir[i][0], c + dir[i][1]);
        }

        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int res = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    res = max(res, dfs(grid, r, c));
                }
            }
        }

        return res;
    }
};
