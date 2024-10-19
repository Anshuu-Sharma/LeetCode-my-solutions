class Solution {
public:
    string invert(const string& s) {
        string result = s;
        for (char& c : result) {
            c = (c == '0') ? '1' : '0'; // Invert the characters
        }
        return result;
    }
    char findKthBit(int n, int k) {
        string prev = "0";

        for(int i = 0; i<n-1; i++){
            string inverted = invert(prev);
            reverse(inverted.begin(), inverted.end());
            prev = prev + "1" + inverted;
        }

        return prev[k-1];
    }
};