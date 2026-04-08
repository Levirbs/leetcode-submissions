class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> count1(26, 0);
        for (char c : s1) count1[c - 'a']++;

        int l = 0; int r = 0;
        vector<int> count2(26, 0);
        while (r < n1) {
            count2[s2[r] - 'a']++;
            r++;
        }
        r--;

        while (r < n2) {
            if (count1 == count2) return true;

            count2[s2[l] - 'a']--;
            l++; 
            r++;
            count2[s2[r] - 'a']++;
        }
        
        return false;
    }
};