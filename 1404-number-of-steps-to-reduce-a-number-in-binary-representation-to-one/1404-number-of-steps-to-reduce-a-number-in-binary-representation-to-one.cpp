class Solution {
public:
    
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for (int i = s.size() - 1; i > 0; --i) {
            int current = (s[i] - '0') + carry;
            
            if (current == 1) {
                //if odd then add 2 steps  
                steps += 2;
                carry = 1;
            } else {
                // if even then add 1 and remove carry
                steps += 1;
            }
        }
        // its imp to understand in this prob is that the carry isnt being set to 0 ever. so its making a rippling effect, keep that in mind
        return steps + carry;
    }
};