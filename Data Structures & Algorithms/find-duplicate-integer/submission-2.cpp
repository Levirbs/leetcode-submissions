// negative marking

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (const int& num : nums) {
            int idx = abs(num) - 1;

            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }

        return -1;
    }
};
