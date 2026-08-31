class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mapa;

        for (const int& num : nums) {
            auto it = mapa.find(num);

            if (it != mapa.end()) return true;

            mapa.insert(num);
        }

        return false;
    }
};