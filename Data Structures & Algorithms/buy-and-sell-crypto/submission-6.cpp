class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minbuy = INT_MAX;
        for (const int& price : prices) {
            minbuy = min(minbuy, price);
            res = max(res, price - minbuy);
        }
        return res;
    }
};
