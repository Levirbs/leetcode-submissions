class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minBuy = INT_MAX;

        for (const int& price : prices) {
            minBuy = min(minBuy, price);
            res = max(res, price - minBuy);
        }

        return res;
    }
};
