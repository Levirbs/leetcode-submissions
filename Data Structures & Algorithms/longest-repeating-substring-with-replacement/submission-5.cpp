class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> window;

        int n = s.length();
        int l = 0;
        int maxf = 0; int res = 0;
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
