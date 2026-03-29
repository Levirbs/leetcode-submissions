class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> anagrams;
        vector<vector<string>> output;
        int groups = 0;
        for(string word : strs) {
            vector<int> count(26, 0);
            for(char letter : word) {
                count[letter - 'a']++;
            }

            if(anagrams.count(count) > 0) {
                output[anagrams[count]].push_back(word);
            } else {
                output.push_back({word});
                anagrams[count] = groups;
                groups++;
            }
        }
        return output;
    }
};
