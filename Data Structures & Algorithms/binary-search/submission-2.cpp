class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            int num = nums[m];
            if (num >= target) {
                r = m;

            } else {
                l = m + 1;
            }
        }

        return (l < nums.size() && nums[l] == target) ? l : -1;
    }
};
