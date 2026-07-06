class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minBuy = INT_MAX;
        
        for (const int& p : prices) {
            minBuy = min(minBuy, p);
            res = max(res, p - minBuy);
        }

        return res;
    }
};
