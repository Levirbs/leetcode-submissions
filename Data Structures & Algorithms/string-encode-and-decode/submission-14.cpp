class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string& word : strs) {
            unsigned char wordLen = word.length();
            encoded += wordLen;
            encoded += word;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> decoded;
        for (int i = 0; i < n; i++) {
            int len = (unsigned char)s[i];

            decoded.push_back(s.substr(i + 1, len));
            i += len;
        }

        return decoded;
    }
};
