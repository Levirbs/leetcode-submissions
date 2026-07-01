class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int res = 0;

        for (const int& price : prices) {
            minBuy = min(minBuy, price);
            res = max(res, price - minBuy);
        }

        return minBuy == INT_MAX ? 0 : res;
    }
};
