class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //constroi o mapa dinamicamente
        unordered_map<int, int> mapa;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int second = target - num;
            if (mapa.count(second)) {
                return {min(i, mapa[second]), max(i, mapa[second])};
            }
            mapa[num] = i;
        }

        return {0, 0};
    }
};
