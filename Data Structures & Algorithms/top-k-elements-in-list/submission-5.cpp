class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n);

        unordered_map<int, int> mapa;
        for (const int& num : nums) mapa[num]++;

        for (const auto& pair : mapa) bucket[pair.second - 1].push_back(pair.first);

        vector<int> res;

        for (int i = n - 1; i >= 0; i--) {
            for (const int& num : bucket[i]) {
                if (res.size() == k) return res;

                res.push_back(num); 
            }
        }

        return res;
    }
};
