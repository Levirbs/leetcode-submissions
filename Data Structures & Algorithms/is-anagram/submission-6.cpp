class Solution {
public:
    bool isAnagram(string s, string t) {
        int tlen = t.length();
        int slen = s.length();
        if (tlen != slen) return false;

        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);

        for (int i = 0; i < slen; i++) {
            smap[s[i] - 'a']++;
            tmap[t[i] - 'a']++;
        }

        return smap == tmap;
    }
};
