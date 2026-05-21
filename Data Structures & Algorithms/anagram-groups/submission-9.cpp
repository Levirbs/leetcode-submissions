class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapa;
        for (const string& word : strs) {
            vector<int> count(26, 0);
            for (const char& c : word) {
                count[c - 'a']++;
            }

            string key;
            for (const int& num : count) {
                key += to_string(num) + "#";
            }

            mapa[key].push_back(word);
        }

        vector<vector<string>> res;
        for (const auto& pair : mapa) {
            res.push_back(pair.second);
        }

        return res;
    }
};
