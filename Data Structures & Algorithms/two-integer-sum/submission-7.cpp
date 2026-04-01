class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            if (prevMap.count(complement)) return {min(i, prevMap[complement]), max(i, prevMap[complement])};
            prevMap[num] = i;
        }
        return {};
    }
};
