class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (const vector<int>& point : points) {
            int x = point[0];
            int y = point[1];
            int distance = (x * x) + (y * y);

            maxHeap.push({distance, {x, y}});
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            auto& el = maxHeap.top();
            res.push_back({el.second.first, el.second.second});
            maxHeap.pop();
        }
        
        return res;
    }
};
