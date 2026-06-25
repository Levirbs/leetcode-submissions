class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int acc = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {
            res[i] *= acc;
            acc *= nums[i];
        }

        acc = 1;

        for (int i = n - 1; i >= 0; i--) {
            res[i] *= acc;
            acc *= nums[i];
        }

        return res;
    }
};
