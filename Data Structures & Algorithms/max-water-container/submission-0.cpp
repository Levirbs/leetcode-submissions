class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0; int r = n - 1; int res = 0;
        while (l < r) {
            int barl = heights[l]; int barr = heights[r];

            int area = min(barl, barr) * (r - l);

            if (area > res) res = area;

            if (barl > barr) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    } 
};