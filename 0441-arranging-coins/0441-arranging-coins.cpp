class Solution {
public:
    int arrangeCoins(int n) {
        /*
        1 + 2 + 3 + 4 + ... maybe n
        
        */
    // binary search or this
        return (sqrt(8.0 * n + 1) - 1) / 2;
    }
};