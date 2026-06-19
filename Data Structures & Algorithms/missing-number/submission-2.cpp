class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (const int& num : nums) {
            sum += num;
        }

        return (((n * n) + n) / 2) - sum;        
    }
};
