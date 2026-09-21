class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for (const int& pile : piles) r = max(r, pile);

        int res = INT_MAX;

        int l = 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int time = 0;
            for (const int& pile : piles) time += (pile + m - 1) / m;

            if (time <= h && m < res){
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};
