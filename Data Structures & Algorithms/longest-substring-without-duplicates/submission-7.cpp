class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int l = 0;
        int res = 0;

        unordered_map<char, int> mapa;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (mapa.count(c)) {
                l = max(l, mapa[c] + 1);
            }
            mapa[c] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
