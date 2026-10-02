class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (tLen > sLen) return "";

        unordered_map<char, int> base;
        unordered_map<char, int> window;

        for (const char& c : t) {
            base[c]++;
        }

        int have = 0;
        int need = base.size();

        int minSize = INT_MAX;
        int i_start;

        int l = 0;
        for (int r = 0; r < sLen; r++) {
            char cr = s[r];
            window[cr]++;
            if (window[cr] == base[cr]) have++;

            while (have == need) {
                int windowSize = r - l + 1;
                if (windowSize < minSize) {
                    minSize = windowSize;
                    i_start = l;
                }
                
                char cl = s[l];
                window[cl]--;
                l++;

                if (window[cl] < base[cl]) have--;
            }
        }

        return minSize == INT_MAX ? "" : s.substr(i_start, minSize);
    }
};
