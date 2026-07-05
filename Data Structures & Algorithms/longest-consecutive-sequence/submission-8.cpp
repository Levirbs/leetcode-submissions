class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapa;

        int n = nums.size();
        for (int i = 0; i < n; i++) mapa[nums[i]] = i;

        int res = 0;
        for (const auto& pair : mapa) {
            if (mapa.count(pair.first - 1)) continue;

            int i = 1;
            while (mapa.count(pair.first + i)) {
                i++;
            }

            res = max(res, i);
        }

        return res;
    }
};
