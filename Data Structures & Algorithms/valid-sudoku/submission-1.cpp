class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> boxes[3][3];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;
                if(rows[r].count(num) || columns[c].count(num) || boxes[r/3][c/3].count(num)) {
                    return false;
                }
                rows[r].insert(num);
                columns[c].insert(num);
                boxes[r/3][c/3].insert(num);
            }
        }
        return true;
    }
};
