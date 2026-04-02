class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > 0) break;
            if (i > 0 && num == nums[i - 1]) continue;

            int l = i + 1; int r = n - 1;
            while (l < r) {
                int sum = num + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({num, nums[l], nums[r]});
                    do {
                        l++;
                    } while(nums[l] == nums[l - 1] && l < r);
                }
            }
        }
        return res;
    }
};

// [-4,-1,-1,0,1,2] 