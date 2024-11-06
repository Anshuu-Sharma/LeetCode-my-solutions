class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());

        string small_one;
        small_one.push_back(s[0]);
        small_one.push_back(s[3]);

        string large_one;
        large_one.push_back(s[1]);
        large_one.push_back(s[2]);

        return (stoi(small_one, nullptr, 10) + stoi(large_one, nullptr, 10));



    }
};