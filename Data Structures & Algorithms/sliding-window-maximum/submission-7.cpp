class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> fila;
        
        int n = nums.size();
        vector<int> res(n - k + 1);
        
        int l = 0;
        for (int r = 0; r < n; r++) {
            int num = nums[r];
            while (!fila.empty() && num > nums[fila.back()]) fila.pop_back();
            fila.push_back(r);

            if (l > fila.front()) fila.pop_front();

            if (r + 1 >= k) {
                res[l] = nums[fila.front()];
                l++;
            }
        }
        return res;
    }
};
