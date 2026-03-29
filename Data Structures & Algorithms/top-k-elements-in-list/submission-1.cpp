class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countHash;
        for (const int num : nums) {
            if (countHash.count(num) > 0) {
                countHash[num]++;
            } else {
                countHash[num] = 0;
            }
        }

        priority_queue<pair<int, int>> heap;
        for (const auto& pair: countHash) {
            heap.push({pair.second, pair.first});
        }

        vector<int> output;
        for (int i = 0; i < k; i++) {
            output.push_back(heap.top().second);
            heap.pop();
        }
        return output;
    }
};
