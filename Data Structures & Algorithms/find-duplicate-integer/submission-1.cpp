// negative marking

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int curr = 0;

        int num = 0;
        while (nums[curr] > 0) {
            num = nums[curr];
            nums[curr] = -1 * abs(num);
            curr = num;
        }

        return num;
    }
};
