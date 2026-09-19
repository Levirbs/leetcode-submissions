class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (tLen > sLen) return "";

        unordered_map<char, int> base;
        unordered_map<char, int> window;
        
        for (const char& c : t) base[c]++;

        int have = 0;
        int need = base.size();

        int i_start;
        int minSize = INT_MAX;

        int l = 0;
        for(int r = 0; r < sLen; r++) {
            char c = s[r];
            window[c]++;
            if (window[c] == base[c]) have++;
            
            while (have == need) {
                int windowSize = r - l + 1;
                if (windowSize < minSize) {
                    i_start = l;
                    minSize = windowSize;
                }

                char cl = s[l];
                window[cl]--;
                
                if (window[cl] + 1 == base[cl]) have--;
                l++;
            }
        }

        return minSize == INT_MAX ? "" : s.substr(i_start, minSize);
    }
};
