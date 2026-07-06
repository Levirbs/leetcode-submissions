class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;

        for (const int& p : piles) r = max(r, p);

        int res = r;
        while (l <= r) {
            int k = (r + l) / 2;
            int time = 0;
            for (const int& p : piles) time += ((p + k - 1) / k);

            if (time <= h) {
                r = k - 1;
                res = k;
            } else {
                l = k + 1;
            }
        }

        return res;
    }
};
