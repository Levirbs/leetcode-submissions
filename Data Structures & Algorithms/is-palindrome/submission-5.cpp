class Solution {
public:
    bool isPalindrome(string s) {
        // isalnum()
        // tolower()
        int n = s.length();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            while (!isalnum(s[l]) && l < r) l++;
            char left = tolower(s[l]);

            while (!isalnum(s[r]) && l < r) r--;
            char right = tolower(s[r]);

            if (left != right) return false;

            l++;
            r--;
        }

        return true;
    }
};
