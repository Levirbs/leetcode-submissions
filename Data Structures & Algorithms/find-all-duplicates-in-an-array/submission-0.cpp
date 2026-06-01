// not in neetcode
// problem link: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (const int& num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                res.push_back(abs(num));
            } else {
                nums[idx] *= -1;
            }
        }

        return res;
    }
};