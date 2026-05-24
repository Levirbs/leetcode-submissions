class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);

        deque<int> pilha;
        
        int l = 0; int r = 0;
        while (r < n) {
            int num = nums[r];
            while (!pilha.empty() && num > nums[pilha.back()]) pilha.pop_back();
            pilha.push_back(r);

            if (l > pilha.front()) pilha.pop_front();

            if (r + 1 >= k) {
                res[l] = nums[pilha.front()];
                l++;
            }
            r++;
        }
        
        return res;
    }
};
