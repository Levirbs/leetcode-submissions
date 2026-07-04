class Solution {
public:
    int inf = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> fila;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) fila.push({i, j});
            }
        }

        while (!fila.empty()) {
            int row = fila.front().first;
            int col = fila.front().second;

            fila.pop();

            int r = row - 1;
            if (r >= 0 && col >= 0 && r < m && col < n && grid[r][col] == inf) {
                grid[r][col] = grid[row][col] + 1;
                fila.push({r, col});
            }

            r = row + 1;
            if (r >= 0 && col >= 0 && r < m && col < n && grid[r][col] == inf) {
                grid[r][col] = grid[row][col] + 1;
                fila.push({r, col});
            }

            int c = col - 1;
            if (row >= 0 && c >= 0 && row < m && c < n && grid[row][c] == inf) {
                grid[row][c] = grid[row][col] + 1;
                fila.push({row, c});
            }

            c = col + 1;
            if (row >= 0 && c >= 0 && row < m && c < n && grid[row][c] == inf) {
                grid[row][c] = grid[row][col] + 1;
                fila.push({row, c});
            }
        }
    }
};
