class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k), minHeap(nums.begin(), nums.end()) {
        while (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);

        } else if (minHeap.top() < val) {
            minHeap.push(val);
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};
