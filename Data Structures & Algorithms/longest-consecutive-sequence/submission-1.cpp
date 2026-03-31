class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mapa;
        for (int num : nums) mapa.insert(num);

        vector<int> firsts;
        for (int num : mapa) {
            if (!mapa.count(num - 1)) firsts.push_back(num);
        }

        int res = 0;
        for (int num : firsts) {
            int i = 0;
            while (mapa.count(num + i)) {
                i++;
            }
            if (i > res) res = i;
        }
        
        return res;
    }
};
