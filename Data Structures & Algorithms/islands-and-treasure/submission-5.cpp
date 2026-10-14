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
                if (grid[i][j] == 0) {
                    fila.push({i, j});
                }
            }
        }

        while (!fila.empty()) {
            int r = fila.front().first;
            int c = fila.front().second;
            fila.pop();

            int next = grid[r][c] + 1;

            for (int i = 0; i < 4; i++) {
                int row = r + dir[i][0];
                int col = c + dir[i][1];

                if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != inf) continue;
                grid[row][col] = next;

                fila.push({row, col});
            }
        }
    }
};
