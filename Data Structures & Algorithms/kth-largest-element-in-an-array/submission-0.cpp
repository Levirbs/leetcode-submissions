class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

        while(minHeap.size() > k) minHeap.pop();

        return minHeap.top();
    }
};
