class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int res = 0;
        for (const int& p : prices) {
            minBuy = min(minBuy, p);
            res = max(res, p - minBuy);
        }
        return res;
    }
};
