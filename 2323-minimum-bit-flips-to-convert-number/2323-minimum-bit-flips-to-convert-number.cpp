class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor1 = start^goal;
        int cnt = 0;
        while(xor1 != 0) {
            xor1 = xor1 & (xor1-1);
            cnt++;
        }
        return cnt;
    }
};