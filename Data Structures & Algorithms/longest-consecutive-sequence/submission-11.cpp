class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapa;

        int n = nums.size();
        for (int i = 0; i < n; i++) mapa[nums[i]] = i;

        int res = 0;
        for (const int& num : nums) {
            if (mapa.count(num - 1)) continue;

            int i = 1;
            while (mapa.count(num + i)) {
                i++;
            }
            res = max(res, i);
        }

        return res;
    }
};
