class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;

        for (const int& pile : piles) r = max(r, pile);

        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;

            int time = 0;
            for (const int& pile : piles) time +=  (pile + k - 1)/ k; // = ceil(pile/k)

            if (time <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
