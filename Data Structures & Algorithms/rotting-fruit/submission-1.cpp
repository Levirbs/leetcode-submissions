class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> fila;
        int bananas = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) fila.push({i, j});

                else if (grid[i][j] == 1) bananas++;
            }
        }
        
        int res = 0;
        while (!fila.empty()) {
            if (bananas == 0) break;
            int levelSize = fila.size();
            
            for (int j = 0; j < levelSize; j++) {
                int x = fila.front().first;
                int y = fila.front().second;
                fila.pop();

                for (int i = 0; i < 4; i++) {
                    int r = x + dir[i][0];
                    int c = y + dir[i][1];

                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) continue;
                    grid[r][c] = 2;

                    bananas--;
                    fila.push({r, c});
                }
            }
            res++;
        }

        return bananas == 0 ? res : -1;
    }
};
