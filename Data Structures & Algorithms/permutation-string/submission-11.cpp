class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();

        if (s1Len > s2Len) return false;

        vector<int> base(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < s1Len; i++) {
            base[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (base[i] == window[i]) matches++;
        }

        int l = 0;
        for (int r = s1Len; r < s2Len; r++) {
            if (matches == 26) return true;

            int cr = s2[r] - 'a';
            window[cr]++;
            if (window[cr] - 1 == base[cr]) {
                matches--;
            } else if (window[cr] == base[cr]) {
                matches++;
            }

            int cl = s2[l] - 'a';
            window[cl]--;
            if (window[cl] + 1 == base[cl]) {
                matches--;
            } else if (window[cl] == base[cl]) {
                matches++;
            }
            l++;
        }

        return matches == 26;
    }
};
