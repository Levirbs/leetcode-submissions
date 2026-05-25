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

            int i = s2[r] - 'a';
            window[i]++;
            if (window[i] == count[i]) {
                matches++;
            } else if (window[i] - 1 == count[i]) {
                matches--;
            }

            i = s2[l] - 'a';
            window[i]--;
            if (window[i] == count[i]) {
                matches++;
            } else if (window[i] + 1 == count[i]) {
                matches--;
            }
            l++;
        }

        return matches == 26;
    }
};
