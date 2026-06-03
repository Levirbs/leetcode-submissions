class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];

            const auto it = mapa.find(comp);

            if (it != mapa.end()) {
                return {min(i, it->second), max(i, it->second)};
            }

            mapa[nums[i]] = i;
        }
        
        return {};
    }
};
