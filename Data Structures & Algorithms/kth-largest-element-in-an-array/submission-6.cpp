class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - k; i++) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
