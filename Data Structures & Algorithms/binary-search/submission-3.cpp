class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int num = nums[m];

            if (num > target) {
                r = m - 1;
            } else if (num < target) {
                l = m + 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};
