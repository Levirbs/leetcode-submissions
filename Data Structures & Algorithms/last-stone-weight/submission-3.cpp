class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int p1 = maxHeap.top(); maxHeap.pop();
            int p2 = maxHeap.top(); maxHeap.pop();

            int left = p1 - p2;
            if (left > 0) maxHeap.push(left);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
