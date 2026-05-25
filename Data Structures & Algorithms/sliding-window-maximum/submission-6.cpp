class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res((n - k + 1), 0);

        deque<int> fila;

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
