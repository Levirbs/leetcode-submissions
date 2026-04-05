class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0]; int maxPro = 0;
        for (int& price : prices) {
            minBuy = min(minBuy, price);
            maxPro = max(maxPro, price - minBuy);
        }
        return maxPro;
    }
};
