class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
// -4, -1, -1, 0, 1, 2
        for (int i = 0; i < n; i++) {
            int fix = nums[i];
            if (fix > 0) break;
            if (i > 0 && nums[i - 1] == fix) continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = fix + nums[j] + nums[k];

                if (sum == 0) {
                    res.push_back({fix, nums[j], nums[k]});
                    do {
                        j++;
                    } while (nums[j - 1] == nums[j] && j < k);
                }

                else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }
};
