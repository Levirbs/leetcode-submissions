class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        unordered_map<char, int> window;

        int res = 0;
        int maxf = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            window[c]++;
            maxf = max(maxf, window[c]);

            while ((r - l + 1) - maxf > k) {
                window[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
