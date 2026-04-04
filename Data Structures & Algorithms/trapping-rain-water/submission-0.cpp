class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); int res = 0;
        int l = 0; int r = n - 1;
        int maxl = height[l]; int maxr = height[r];
        while (l < r) {
            if (maxl < maxr) {
                l++;
                int curr = height[l];
                maxl = max(maxl, curr);

                res += maxl - curr;
            } else {
                r--;
                int curr = height[r];
                maxr = max(maxr, curr);

                res += maxr - curr;
            }
        }
        return res;
    }
};
