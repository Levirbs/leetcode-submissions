class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            int num = nums[m];

            if (num >= nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return nums[r];
    }
};
