class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> lastSeen;
        int curr = 0; int res = 0;
        int n = s.length();
        int l = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            if (lastSeen.count(c) && l < lastSeen[c] + 1) {
                res = max(res, curr);
                l = lastSeen[c] + 1;
                curr = r - l + 1;
                lastSeen[c] = r;
            } else {
                lastSeen[c] = r;
                curr++;
            }

        }
        return max(res, curr);
    }
};
