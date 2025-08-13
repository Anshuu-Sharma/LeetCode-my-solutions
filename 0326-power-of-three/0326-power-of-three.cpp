class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467 is the largest power of 3 in 32-bit range
        return n > 0 && 1162261467 % n == 0;
    }
};