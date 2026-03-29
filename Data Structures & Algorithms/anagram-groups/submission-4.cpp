class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string word : strs) {
            vector<int> count(26, 0);

            for (char letter : word) {
                count[letter - 'a']++;
            }

            string key = "";
            for (int num : count) {
                key += to_string(num) + ",";
            }

            anagrams[key].push_back(word);
        }

        vector<vector<string>> output;
        for (const auto& pair : anagrams) {
            output.push_back(pair.second);
        }
        return output;
    }
};
