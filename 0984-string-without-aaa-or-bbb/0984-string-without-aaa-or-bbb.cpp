class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";
        while (a > 0 || b > 0) {
            bool writeA = false;
            int n = res.length();
            
            // If the last two characters are 'b', we MUST write 'a'
            if (n >= 2 && res[n - 1] == 'b' && res[n - 2] == 'b') {
                writeA = true;
            } 
            // If the last two characters are 'a', we CANNOT write 'a'
            else if (n >= 2 && res[n - 1] == 'a' && res[n - 2] == 'a') {
                writeA = false;
            } 
            // Otherwise, write whichever character has a higher remaining count
            else {
                writeA = (a >= b);
            }
            
            if (writeA) {
                res += 'a';
                a--;
            } else {
                res += 'b';
                b--;
            }
        }
        
        return res;
    }
};