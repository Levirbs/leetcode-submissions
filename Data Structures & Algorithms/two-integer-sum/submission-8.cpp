class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;

        for (int i = 0; i < nums.size(); i++) {
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
