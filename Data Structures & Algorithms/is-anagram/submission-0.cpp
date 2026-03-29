class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> mapa1;
        unordered_map<char, int> mapa2;

        for (int i = 0; i < s.length(); i++) {
            mapa1[s[i]]++;
            mapa2[t[i]]++;
        }
        return mapa1 == mapa2;
    }
};
