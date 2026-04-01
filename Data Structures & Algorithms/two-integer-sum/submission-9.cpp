class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int complement = target - num;

            auto it = prevMap.find(complement);
            
            if(it != prevMap.end()) {
                return { it->second, i };
            }
            prevMap[num] = i;
        }
        return {};
    }
};
