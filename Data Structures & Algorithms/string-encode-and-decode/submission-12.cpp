class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& word : strs) {
            unsigned char size = word.length();
            res += size;
            res += word;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.length();
        int i = 0;
        while (i < n) {
            int wordLen = (unsigned char)s[i];
            res.push_back(s.substr(i + 1, wordLen));
            i += wordLen + 1;
        }
        return res;
    }
};
