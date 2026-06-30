class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> window(26, 0);

        int maxf = 0; int l = 0; int res = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            window[c - 'A']++;
            
            maxf = max(maxf, window[c - 'A']);
            
            while ((r - l + 1) - maxf > k) {
                window[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
