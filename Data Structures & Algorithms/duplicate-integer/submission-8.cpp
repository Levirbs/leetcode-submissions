class Solution {
private:
    unordered_set<int> mapa;
public:
    bool hasDuplicate(vector<int>& nums) {
        for (const int& num : nums) {
            if (mapa.count(num)) return true;

            mapa.insert(num);
        }

        return false;
    }
};