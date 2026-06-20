class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        int digits[6]; // Since num2 <= 10^5, a number has at most 6 digits
        
        for (int i = num1; i <= num2; ++i) {
            int temp = i;
            int n = 0;
            
            // Extract digits mathematically 
            // Note: Digits populate in reverse, but peak/valley logic is symmetric!
            while (temp > 0) {
                digits[n++] = temp % 10;
                temp /= 10;
            }
            
            // Numbers with fewer than 3 digits have 0 waviness
            if (n < 3) continue;
            
            // Check for peaks and valleys
            for (int j = 1; j < n - 1; ++j) {
                if ((digits[j] > digits[j - 1] && digits[j] > digits[j + 1]) || 
                    (digits[j] < digits[j - 1] && digits[j] < digits[j + 1])) {
                    total_waviness++;
                }
            }
        }
        
        return total_waviness;
    }
};