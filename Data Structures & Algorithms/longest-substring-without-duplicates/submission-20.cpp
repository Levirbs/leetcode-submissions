class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> mapa;

        int l = 0;
        int res = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (mapa.count(c)) {
                l = max(mapa[c] + 1, l);
            }

            res = max(res, r - l + 1);
            mapa[c] = r;
        }

        return res;
    }
};
