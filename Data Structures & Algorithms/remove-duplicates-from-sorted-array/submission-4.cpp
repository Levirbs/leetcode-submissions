class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = INT_MAX;

        vector<int> res;
        for (const int& num : nums) {
            if (num == prev) continue;

            prev = num;
            res.push_back(num);
        }
        nums = res;

        return res.size();
    }
};