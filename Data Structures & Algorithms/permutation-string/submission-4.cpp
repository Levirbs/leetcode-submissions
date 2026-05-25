class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> count(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < n1; i++) {
            count[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] == window[i]) matches++;
        }

        int l = 0;
        for (int r = n1; r < n2; r++) {
            if (matches == 26) return true;

            char c = s2[r] - 'a';
            window[c]++;
            if (window[c] == count[c]) {
                matches++;
            } else if (window[c] - 1 == count[c]) { 
                matches--;
            }

            c = s2[l] - 'a';
            window[c]--;
            if (window[c] == count[c]) {
                matches++;
            } else if (window[c] + 1 == count[c]) { 
                matches--;
            }
            l++;
        }

        return matches == 26;
    }
};
