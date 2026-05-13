class Solution {
public:
    bool isPalindrome(string s) {
        // isalnum()
        // tolower()
        if (s.empty()) return true;

        int n = s.length();
        int l = 0; int r = n - 1;

        while (l < r) {
            while (!isalnum(s[l]) && l < r) {
                l++;
            }
            char leftc = tolower(s[l]);

            while (!isalnum(s[r]) && l < r) {
                r--;
            }
            char rightc = tolower(s[r]);

            if (l > r || rightc != leftc) return false;
            l++; r--;
        }
        return true;
    }
};
