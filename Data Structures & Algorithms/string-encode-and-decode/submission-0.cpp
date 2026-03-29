class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string word : strs) {
            unsigned char size = word.size();
            encoded += size;
            encoded += word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> decoded;
        while (i < s.size()) {
            int wordSize = (unsigned char)s[i];
            decoded.push_back(s.substr(i + 1, wordSize));
            i += wordSize + 1;
        }
        return decoded;
    }
};
