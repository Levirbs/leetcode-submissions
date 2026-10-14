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
        int i = 0;
        int n = s.length();

        while (i < n) {
            int len = (unsigned char)s[i++];

            decoded.push_back(s.substr(i, len));
            i += len;
        }
        return decoded;
    }
};
