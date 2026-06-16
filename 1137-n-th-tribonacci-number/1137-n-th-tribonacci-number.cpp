class Solution {
public:
    int tribonacci(int n) {
        // Base cases defined by the problem
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Variables to store the previous three Tribonacci numbers
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        
        // Calculate from T_3 up to T_n
        for (int i = 3; i <= n; ++i) {
            int next = t0 + t1 + t2; // T_{n+3} = T_n + T_{n+1} + T_{n+2}
            
            // Shift the window forward
            t0 = t1;
            t1 = t2;
            t2 = next;
        }
        
        return t2;
    }
};
