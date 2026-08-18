class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string& word : strs) {
            unsigned char len = word.length();
            encoded += len;
            encoded += word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int slen = s.length();
        int i = 0;
        while (i < slen) {
            int wordLen = (unsigned char) s[i];
            i++;
            
            decoded.push_back(s.substr(i, wordLen));
            i += wordLen;
        }

        return decoded;
    }
};
