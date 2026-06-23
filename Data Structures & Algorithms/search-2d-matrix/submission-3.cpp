class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int l = 0;
        int r = rows * cols - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int num = matrix[m / cols][m % cols];

            if (num == target) return true;

            if (num < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
};
