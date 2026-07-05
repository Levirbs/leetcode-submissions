class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (tLen != sLen) return false;

        unordered_map<char, int> mapaS;
        unordered_map<char, int> mapaT;

        for (int i = 0; i < sLen; i++) {
            mapaS[s[i]]++;
            mapaT[t[i]]++;
        }

        return mapaS == mapaT ? true : false;
    }
};
