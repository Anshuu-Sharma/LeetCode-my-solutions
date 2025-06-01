class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        long long firstMin = max(0, n - limit - limit);
        long long firstMax = min(limit, n);
        for (int x = firstMin; x <= firstMax; ++x) {
            int minY = max(0, n - x - limit);
            int maxY = min(limit, n - x);
            if (minY <= maxY) {
                cnt += (maxY - minY + 1);
            }
        }
        return cnt;
    }
};
