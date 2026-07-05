class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> fila;
        int frutas = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (v == 2) fila.push({i, j});

                if (v == 1) frutas++;
            }
        }

        vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int res = 0;
        while (!fila.empty()) {
            if (frutas == 0) return res;
            int levelSize = fila.size();

            for (int i = 0; i < levelSize; i++) {
                int r = fila.front().first;
                int c = fila.front().second;
                fila.pop();

                for (const auto& dir : direcoes) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != 1) continue;

                    frutas--;
                    grid[row][col] = 2;
                    fila.push({row, col});
                }
            }
            res++;
        }

        return frutas > 0 ? -1 : res;
    }
};
