class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[3][3];

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char c = board[row][col];
                if (c == '.') continue;

                if (rows[row].count(c)) return false;
                if (cols[col].count(c)) return false;
                if (squares[row / 3][col / 3].count(c)) return false;

                rows[row].insert(c);
                cols[col].insert(c);
                squares[row / 3][col / 3].insert(c);
            }
        }

        return true;
    }
};
