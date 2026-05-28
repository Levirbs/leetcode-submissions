class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int res = 0;

        int l = 0; int r = n - 1;
        int lmax = heights[l]; int rmax = heights[r];
        while (l < r) {
            if (lmax > rmax) {
                res = max(res, (r - l) * rmax);
                r--;
                rmax = max(rmax, heights[r]);
            } else {
                res = max(res, (r - l) * lmax);
                l++;
                lmax = max(lmax, heights[l]);
            }
        }

        return res;
    }
};
