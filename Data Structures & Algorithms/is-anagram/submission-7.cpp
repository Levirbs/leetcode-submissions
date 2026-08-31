class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen != tLen) return false;

        vector<int> mapaS(26, 0);
        vector<int> mapaT(26, 0);

        for (int i = 0; i < sLen; i++) {
            mapaS[s[i] - 'a']++;
            mapaT[t[i] - 'a']++;
        }

        return mapaS == mapaT;
    }
};
