class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        // Continue while n is not 1 and we haven't seen 'n' before
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            
            int ans = 0;
            while (n > 0) {
                int temp = n % 10;
                ans += temp * temp;
                n = n / 10;
            }
            // Update n to the newly calculated sum of squares
            n = ans; 
        }
        
        // If the loop exits because n == 1, it's a happy number
        return n == 1;
    }
};
