class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_set<int> mapa;

        for (const int& num : nums) mapa.insert(num);

        for (const int& num : nums) {
            if (mapa.count(num - 1)) continue;

            int i = 0;
            while (mapa.count(num + i)) {
                i++;
            }
            res = max(res, i);
        }
        return res;
    }
};
