class Solution {
public:
    int scoreOfString(string s) {
        int i = 0 , j = 1;
        int sum = 0;
        while(i<=s.size()-2)
        {
            sum += abs(int(s[i]) - int(s[j]));
            i++;
            j++;
        }
        return sum;
    }
};