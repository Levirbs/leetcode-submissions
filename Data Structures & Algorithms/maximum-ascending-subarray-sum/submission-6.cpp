class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int prev = 0;
        int res = 0;
        
        for (const int& num : nums) {
            if (prev < num) {
                sum += num;
            } else {
                sum = num;
            }
            prev = num;
            res = max(res, sum);
        }

        return res;
    }
};