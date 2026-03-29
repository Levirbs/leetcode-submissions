class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const int& num : nums) {
            count[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto& pair : count) {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> output;
        for (int i = nums.size(); i > 0; i--) {
            for (int n : bucket[i]) {
                output.push_back(n);
            }
            if (output.size() == k) return output;
        }
    }
};
