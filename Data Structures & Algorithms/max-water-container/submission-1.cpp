class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n - 1;

        int hl = heights[l];
        int hr = heights[r];
        int res = 0;

        while (l < r) { 
            if (hl > hr) {
                res = max(res, (r - l) * hr);
                r--;
                hr = heights[r];
            } else {
                res = max(res, (r - l) * hl);
                l++;
                hl = heights[l];
            }
        }
        return res;
    }
};