class Solution {
public:
    bool isPalindrome(string s) {
        // isalnum()
        // to_lower()
        int n = s.length();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            while (!isalnum(s[l]) && l < r) l++;
            char cleft = tolower(s[l]);

            while (!isalnum(s[r]) && l < r) r--;
            char cright = tolower(s[r]);

            if (cleft != cright) return false;

            l++; r--;
        }

        return true;
    }
};
