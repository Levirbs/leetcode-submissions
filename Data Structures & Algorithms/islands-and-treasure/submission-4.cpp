class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int inf = 2147483647;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> fila;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) fila.push({i, j});
            }
        }

        while (!fila.empty()) {
            int x = fila.front().first;
            int y = fila.front().second;
            fila.pop();

            int next = grid[x][y] + 1;
            for (int i = 0; i < 4; i++) {
                int r = x + dir[i][0];
                int c = y + dir[i][1];

                if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != inf) continue;

                grid[r][c] = next;
                fila.push({r, c});
            }
        }
    }
};
