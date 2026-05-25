class Solution {
public:
    string minWindow(string s, string t) {
        // map, cord
        int sLen = s.length();
        int tLen = t.length();

        if (tLen > sLen || tLen == 0) return "";

        unordered_map<char, int> count;
        unordered_map<char, int> window;

        for (const char& c : t) count[c]++;

        int need = count.size();
        int have = 0;
        
        int cord = 0; int minSize = INT_MAX;

        int l = 0;
        for (int r = 0; r < sLen; r++) {
            char c = s[r];
            window[c]++;
            if (window[c] == count[c]) have++;

            while (have == need) {
                int windowSize = r - l + 1;
                if (minSize > windowSize) {
                    cord = l;
                    minSize = windowSize;
                }
                char c = s[l];
                window[c]--;
                if (window[c] + 1 == count[c]) have--;
                l++;
            } 
        }

        return minSize == INT_MAX ? "" : s.substr(cord, minSize);
    }
};
