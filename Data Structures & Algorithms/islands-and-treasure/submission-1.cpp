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

            vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (const auto& dir : direcoes) {
                int r = row + dir.first;
                int c = col + dir.second;

                if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == inf) {
                    grid[r][c] = grid[row][col] + 1;
                    fila.push({r, c});
                }
            }
        }
    }
};
