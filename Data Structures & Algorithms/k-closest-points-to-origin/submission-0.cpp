class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (const vector<int>& point : points) {
            int x = point[0]; int y = point[1];
            int distance = (x*x) + (y*y);

            if (maxHeap.size() < k) {
                maxHeap.push({distance, {x, y}});

            } else if (distance < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({distance, {x, y}});

            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};
