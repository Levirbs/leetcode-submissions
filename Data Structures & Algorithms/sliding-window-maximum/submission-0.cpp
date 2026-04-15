class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> window;
        int l = 0; int r = 0;
        
        while (r < n) {
            int num = nums[r];
            while (!window.empty() && nums[window.back()] < num) window.pop_back();
            window.push_back(r);

            if (l > window.front()) window.pop_front();

            if (r + 1 >= k) {
                res[l] = nums[window.front()];
                l++;
            }
            r++;
        }
        return res;
    }
};
