class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        
        unordered_map<char, int> countT;
        unordered_map<char, int> window;
        for (char c : t) {
            countT[c]++;
        }
        
        int ssize = s.length();
        int l = 0; int maxLen = INT_MAX;
        int cord = 0;
        int have = 0; int need = countT.size();

        for (int r = 0; r < ssize; r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && countT[c] == window[c]) have++;

            while (have == need) {
                int windowSize = (r - l + 1);
                if (windowSize < maxLen) {
                    maxLen = windowSize;
                    cord = l;
                }
                
                char remov = s[l];
                window[remov]--;
                if (countT.count(remov) && window[remov] < countT[remov]) {
                    have--;
                }
                l++;
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(cord, maxLen);
    }
};