class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            vector<int> wordMap(26, 0);
            for (char c : word) {
                wordMap[c - 'a']++;
            }

            string key;
            for (int num : wordMap) key += to_string(num) + "#";

            groups[key].push_back(word);
        }

        vector<vector<string>> res;

        for (const auto& pair : groups) {
            res.push_back(pair.second);
        }

        return res;
    }
};
