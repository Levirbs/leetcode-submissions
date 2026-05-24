class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (tLen == 0 || tLen > sLen) return "";

        unordered_map<char, int> window;
        unordered_map<char, int> tMapa;

        for (const char& c : t) tMapa[c]++;

        int need = tMapa.size();
        int have = 0;

        int l = 0; int maxLen = INT_MAX; int i = 0;
        for (int r = 0; r < sLen; r++) {
            char c = s[r];

            window[c]++;
            if (window[c] == tMapa[c]) have++;

            while (have == need) {
                int windowSize = r - l + 1;
                if (maxLen > windowSize) {
                    maxLen = windowSize;
                    i = l;
                }
                char c = s[l];
                window[c]--;
                if (window[c] + 1 == tMapa[c]) have--;
                l++;
            }

        }

        return maxLen == INT_MAX ? "" : s.substr(i, maxLen);
    }
};
