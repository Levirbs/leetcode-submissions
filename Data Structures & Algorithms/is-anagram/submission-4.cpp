class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mapas(26, 0);
        vector<int> mapat(26, 0);

        int ns = s.length();
        int nt = t.length();
        if (ns != nt) return false;

        for (int i = 0; i < ns; i++) {
            mapas[s[i] - 'a']++;
            mapat[t[i] - 'a']++;
        }

        return mapas == mapat;
    }
};
