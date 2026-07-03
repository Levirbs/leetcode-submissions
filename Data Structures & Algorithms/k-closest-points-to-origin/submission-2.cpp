class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const vector<int>& point : points) {
            int x = point[0]; 
            int y = point[1];
            int distance = (x*x) + (y*y);

            if (maxHeap.size() < k) {
                maxHeap.push({distance, point});
            } else if (distance < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({distance, point});
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
};