class Solution {
public:
int M = 1e9+7;
    int concatenatedBinary(int n) {
        long s = 0;

        for(int i = 1; i<=n; i++){
            int x = log2(i) + 1;
            s = ((s << x)%M + i)%M; 
        }

        return s;

    }
};