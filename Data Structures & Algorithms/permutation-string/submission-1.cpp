class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(); int n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) matches++;
        }

        int l = 0;
        for (int r = n1; r < n2; r++) {
            if (matches == 26) return true;

            int i = s2[r] - 'a';
            count2[i]++;
            if (count2[i] == count1[i]) {
                matches++;
            } else if (count2[i] - 1 == count1[i]) {
                matches--;
            }

            i = s2[l] - 'a';
            count2[i]--;
            if (count2[i] == count1[i]) {
                matches++;
            } else if (count2[i] + 1 == count1[i]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
