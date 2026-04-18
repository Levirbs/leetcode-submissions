class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> fila;

        int l = 0; int r = 0;
        while (r < n) {
            while (!fila.empty() && nums[fila.back()] < nums[r]) fila.pop_back();
            fila.push_back(r);

            if (l > fila.front()) fila.pop_front();

            if (r + 1 >= k) {
                res[l] = nums[fila.front()];
                l++;
            }
            r++;
        }
        return res;
    }
};
