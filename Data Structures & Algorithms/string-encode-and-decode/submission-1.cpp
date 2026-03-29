class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& word : strs) {
            encoded += to_string(word.size()) + "#" + word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> decoded;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int wordSize = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + wordSize;
            decoded.push_back(s.substr(i, wordSize));
            i = j;
        }
        return decoded;
    }
};
