class Solution {
public:
    bool isPowerOfFour(int n) {
        // this worked for power of 3 only as there was no other number to conflict, but here are 2, 8 etc;
        // return n>0 && 1073741824 % n == 0;

        return n>0 &&
        (n & (n-1)) == 0 &&
        (n-1)% 3 == 0;

    }
};