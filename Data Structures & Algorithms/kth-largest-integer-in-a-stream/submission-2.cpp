class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> stream;
    int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k), stream(nums.begin(), nums.end()) {
        while (k < stream.size()) {
            stream.pop();
        }
    }
    
    int add(int val) {
        if (stream.size() < k) {
            stream.push(val);
        } else if (stream.top() < val) {
            stream.pop();
            stream.push(val);
        }

        return stream.top();
    }
};
