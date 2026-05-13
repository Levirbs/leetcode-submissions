class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            vector<int> count(26, 0);
            for (const char& c : word) {
                count[c - 'a']++;
            }

            string key;
            for (const int& i : count) {
                key += to_string(i) + ",";
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> res;
        for (const auto& group : groups) {
            res.push_back(group.second);
        }
        return res;
    }
};
