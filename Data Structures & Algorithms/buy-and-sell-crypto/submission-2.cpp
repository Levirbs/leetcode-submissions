class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minBuy = INT_MAX;

        for (const int& price : prices) {
            minBuy = min(minBuy, price);
            maxProf = max(maxProf, price - minBuy);
        }
        return maxProf;
    }
};
