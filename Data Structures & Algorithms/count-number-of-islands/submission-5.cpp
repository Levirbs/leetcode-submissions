class Solution {
private:
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (x >= rows || x < 0 || y >= cols || y < 0 || grid[x][y] == '0') return;
        grid[x][y] = '0';

        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dir[i][0], y + dir[i][1]);
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
