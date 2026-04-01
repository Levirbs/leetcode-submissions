class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.length() - 1;
        
        while (left < right) {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }
            char leftchar = tolower(s[left]);

            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            char rightchar = tolower(s[right]);

            if (leftchar != rightchar) return false;

            left++; right--;
        }
        return true;
    }
};
