class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapa;

        for (const string& word : strs){
            vector<int> count(26, 0);
            for (const char& c : word) {
                count[c - 'a']++;
            }
            
            string vetor;
            for (const int& i : count) {
                vetor += to_string(i) + "#";
            }

            mapa[vetor].push_back(word);
        }

        vector<vector<string>> res;
        for (const auto& groups : mapa) {
            res.push_back(groups.second);
        }

        return res;
    }
};
