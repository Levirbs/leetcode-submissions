class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (tLen > sLen || tLen == 0) return "";

        unordered_map<char, int> window;
        unordered_map<char, int> mapaT;

        for (const char& c : t) mapaT[c]++;

        int have = 0;
        int need = mapaT.size();

        int minLen = INT_MAX;
        int cord = 0;

        int l = 0;
        for (int r = 0; r < sLen; r++) {
            int c = s[r];
            window[c]++;
            if (window[c] == mapaT[c]) have++;

            while (have == need) {
                int windowSize = r - l + 1;
                if (minLen > windowSize) {
                    minLen = windowSize;
                    cord = l;
                }
                c = s[l];

                window[c]--;
                if (window[c] + 1 == mapaT[c]) have--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(cord, minLen);
    }
};
