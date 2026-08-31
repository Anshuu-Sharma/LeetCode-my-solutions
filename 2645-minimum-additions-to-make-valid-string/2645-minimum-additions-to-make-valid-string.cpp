class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int k = 1; // Number of "abc" blocks needed
        
        for (int i = 1; i < n; i++) {
            // If current character is less than or equal to previous,
            // it must belong to a new "abc" block
            if (word[i] <= word[i - 1]) {
                k++;
            }
        }
        
        // Total characters in k "abc" blocks is 3 * k.
        // Insertions needed = total characters - original length
        return 3 * k - n;
    }
};