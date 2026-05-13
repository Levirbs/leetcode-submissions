class Solution {
public:
    string minWindow(string s, string t) {
        int tLen = t.length(); int sLen = s.length();
        if (tLen == 0 || tLen > sLen) return "";

        unordered_map<int, int> tMap;
        unordered_map<int, int> window;

        for (const char& c : t) tMap[c]++;

        int have = 0; int need = tMap.size();
        int maxLen = INT_MAX;
        int l = 0;
        int cord = 0;

        for (int r = 0; r < sLen; r++) {
            char c = s[r];
            window[c]++;

            if (tMap.count(c) && tMap[c] == window[c]) have++;

            while (have == need) {
                int windowSize = r - l + 1;
                if (windowSize < maxLen) {
                    maxLen = windowSize;
                    cord = l;
                }

                char remov = s[l];
                window[remov]--;

                if (tMap.count(remov) && window[remov] + 1 == tMap[remov]) have--;
                l++;
            }
        }

        return maxLen == INT_MAX ? "" : s.substr(cord, maxLen);
    }
};
