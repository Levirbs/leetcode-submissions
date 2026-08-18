class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucketsort
        int n = nums.size();
        vector<vector<int>> bucket(n);

        unordered_map<int, int> mapa;

        for (const int& num : nums) mapa[num]++;

        for (const auto& pair : mapa) {
            bucket[pair.second - 1].push_back(pair.first);
        }

        vector<int> res;

        while (true) {
            for (int i = n - 1; i >= 0; i--) {
                for (int num : bucket[i]) {
                    res.push_back(num);
                    if (res.size() == k) return res;
                }
            }
        }

        return {};
    }
};
