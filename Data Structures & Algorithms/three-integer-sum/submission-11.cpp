class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int fix = nums[i];
            if (fix > 0) break;
            if (i > 0 && fix == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = fix + nums[l] + nums[r];

                if (sum == 0) {
                    res.push_back({fix, nums[l], nums[r]});

                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return res;
    }
};
