class Solution {
private:
    int inf = 2147483647;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> fila;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) fila.push({r, c});
            }
        }

        while (!fila.empty()) {
            int r = fila.front().first;
            int c = fila.front().second;
            fila.pop(); 

            int curr = grid[r][c];

            for (int i = 0; i < 4; i++) {
                int x = r + dir[i][0];
                int y = c + dir[i][1];

                if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == inf) {
                    grid[x][y] = curr + 1;
                    fila.push({x, y});
                }
            }
        }
    }
};
