class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int gcdLen = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLen);
    }
    int gcd(int s1, int s2) {
        return s2 == 0 ? s1 : gcd(s2, s1 % s2);
    }
};