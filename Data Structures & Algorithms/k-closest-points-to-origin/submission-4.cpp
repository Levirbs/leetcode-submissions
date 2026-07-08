class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (const vector<int>& p : points) {
            int x = p[0];
            int y = p[1];

            if (maxHeap.size() < k) {
                maxHeap.push({(x*x) + (y*y), {x, y}});
            } else {
                int d = (x*x) + (y*y);
                if (d < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({d, {x, y}});
                }
            }
        }
        
        vector<vector<int>> res;

        while (!maxHeap.empty()) {
            auto& p = maxHeap.top();
            res.push_back({p.second.first, p.second.second});
            maxHeap.pop();
        }

        return res;
    }
};
