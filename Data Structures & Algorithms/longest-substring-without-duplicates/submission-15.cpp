class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> window;

        int l = 0; int res = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (window.count(c)) {
                l = max(l, window[c] + 1);
            }
            window[c] = r;

            res = max(res, r - l + 1);
        }

        return res;
    }
};
