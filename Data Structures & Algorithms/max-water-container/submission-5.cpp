class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int n = heights.size();

        int l = 0;
        int r = n - 1;

        int hl;
        int hr;

        while (l < r){
            hl = heights[l];
            hr = heights[r];

            if (hl < hr) {
                res = max(res, (r - l) * hl);
                l++;

            } else {
                res = max(res, (r - l) * hr);
                r--;

            }
        }

        return res;
    }
};
