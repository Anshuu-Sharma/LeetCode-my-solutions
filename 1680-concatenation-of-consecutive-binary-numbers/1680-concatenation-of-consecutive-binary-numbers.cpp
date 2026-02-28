class Solution {
public:
int M = 1e9+7;
    int concatenatedBinary(int n) {
        long s = 0;
        int digits = 0;
        for(int i = 1; i<=n; i++){
            // int x = log2(i) + 1;
            // use the concept of power of 2 to find the number of bits to shift the number
            // When you write int i = 5;, you see the decimal number 5. However, in your computer's memory, it is already stored as 101.
            if((i & (i-1)) == 0) digits++;

            s = ((s << digits)%M + i)%M; 
        }

        return s;

    }
};