class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> tuplas;
        int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++) {
            tuplas.push_back({nums[i], i});
        }

        sort(tuplas.begin(), tuplas.end());


        int left = 0;
        int right = numsSize - 1;

        while (left < right) {
            int sum = tuplas[left].first + tuplas[right].first;

            if (sum == target) {
                return {min(tuplas[left].second, tuplas[right].second),
                max(tuplas[left].second, tuplas[right].second)};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
    }
};
