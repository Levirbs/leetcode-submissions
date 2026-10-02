class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mapa;

        for (const int& num : nums) {
            if (mapa.count(num)) return true;

            mapa.insert(num);
        }

        return false;
    }
};