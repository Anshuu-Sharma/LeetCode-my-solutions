class Solution {
    //KNK
    long mod = 1e9 + 7;
    long modpow(long base, long exp) {
        long ans = 1;
        while (exp) {
            if (exp & 1) ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return modpow(5, (n + 1) / 2) * modpow(4, n / 2) % mod;
    }
};
