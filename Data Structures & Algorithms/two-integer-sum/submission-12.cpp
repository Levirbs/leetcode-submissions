class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int complement = target - num;
            
            auto it = mapa.find(complement);

            if (it != mapa.end()) {
                return {min(i, it->second), max(i, it->second)};
            }
            mapa[num] = i;
        }

        return {0, 0};
    }
};
