class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mapa;
        for (int i = 0; i < nums.size(); i++) {
            if (mapa.count(nums[i]) > 0) return true;
            mapa.insert(nums[i]);
        }
        return false;
    }
};