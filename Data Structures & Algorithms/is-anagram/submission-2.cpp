class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.length();
        if(size != t.length()) return false;

        unordered_map<char, int> mapaS;
        unordered_map<char, int> mapaT;

        for (int i = 0; i < size; i++) {
            mapaS[s[i]]++;
            mapaT[t[i]]++;
        }

        return mapaS == mapaT;
    }
};
