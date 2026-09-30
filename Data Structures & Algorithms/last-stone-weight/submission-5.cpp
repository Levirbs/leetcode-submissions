class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap(stones.begin(), stones.end());

        while (maxheap.size() > 1) {
            int s1 = maxheap.top(); maxheap.pop();
            int s2 = maxheap.top(); maxheap.pop();

            int rest = s1 - s2;

            if (rest > 0) maxheap.push(rest);
        }

        return maxheap.empty() ? 0 : maxheap.top();
    }
};
