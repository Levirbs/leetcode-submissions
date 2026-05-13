class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> lastSeen;
        int res = 0;
        int n = s.length();
        int l = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (lastSeen.count(c)) {
                l = max(l, lastSeen[c] + 1);
            }
                lastSeen[c] = r;
                res = max(res, r - l + 1);
        }
        return res;
    }
};
