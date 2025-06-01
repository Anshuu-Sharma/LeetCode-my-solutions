class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for (int x = 0; x <= limit; ++x) {
            int minY = max(0, n - x - limit);
            int maxY = min(limit, n - x);
            if (minY <= maxY) {
                cnt += (maxY - minY + 1);
            }
        }
        return cnt;
    }
};
