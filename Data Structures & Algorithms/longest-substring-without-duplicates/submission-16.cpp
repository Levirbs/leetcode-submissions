class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapa;

        int n = s.length();
        int l = 0;
        int r = 0;

        int res = 0;
        while (r < n) {
            char c = s[r];
            
            if (mapa.count(c) && l <= mapa[c]) {
                l = mapa[c] + 1;
            }

            mapa[c] = r;
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
