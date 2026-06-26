class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int num = numbers[l] + numbers[r];

            if (num == target) return {l + 1, r + 1};

            if (num < target) {
                l++;
            } else {
                r--;
            }
        }

        return {};
    }
};
