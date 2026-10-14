class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> fila;
    
        int fruits = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;

                if (grid[i][j] == 2) {
                    fila.push({i, j});
                    
                } else {
                    fruits++;
                }
            }
        }

        int time = 0;
        while (!fila.empty()) {
            if (fruits == 0) return time;
            time++;

            int levelSize = fila.size();

            for (int i = 0; i < levelSize; i++) {
                int r = fila.front().first;
                int c = fila.front().second;
                fila.pop();

                for (int j = 0; j < 4; j++) {
                    int row = r + dir[j][0];
                    int col = c + dir[j][1];

                    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) continue;
                    grid[row][col] = 2;

                    fruits--;
                    fila.push({row, col});
                }
            }
        }

        return fruits == 0 ? time : -1;
    }
};
