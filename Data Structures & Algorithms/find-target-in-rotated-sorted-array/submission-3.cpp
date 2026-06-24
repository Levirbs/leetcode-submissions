class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int num = nums[m];

            if (num == target) return m;

            if (num > nums[r]) {
                if (target >= nums[l] && target < num) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target > num && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
