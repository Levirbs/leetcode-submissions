class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> blocks[3][3];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                if (rows[i].count(c)) return false;
                if (cols[j].count(c)) return false;
                if (blocks[i / 3][j / 3].count(c)) return false;

                rows[i].insert(c);
                cols[j].insert(c);
                blocks[i / 3][j / 3].insert(c);
            }
        }

        return true;
    }
};
