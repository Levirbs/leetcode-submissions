class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (const int& num : nums) {
            int idx = abs(num) - 1;

            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};