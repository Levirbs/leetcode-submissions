class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length();

        while(l < r) {
           while (!isalnum(s[l]) && l < r) l++;
           char leftc = tolower(s[l]);

           while (!isalnum(s[r]) && l < r) r--;
           char rightc = tolower(s[r]);

           if (leftc != rightc) return false;
           l++; r--;
        }

        return true;
        
    }
};
