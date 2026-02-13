class Solution {
public:
    int longestPairBalanced(string s, char x, char y, char z){
        //KNK
        int ans = 0, x_count = 0, y_count = 0;
        map<int, int> mp;
        mp[0] = 0; // initial position for diff = 0
        for(int i=0 ; i<s.size() ; ++i){
                if(s[i] == z){  // when encountering the third character
                    mp.clear();
                    mp[0]=i+1; // reset the starting point
                    x_count = y_count = 0;
                    continue;
                }
                else if(s[i] == x)
                    ++x_count;
                else
                    ++y_count;
                int diff = x_count-y_count;
                if(mp.count(diff)){
                    ans = max(ans, i-mp[diff]+1); // found a substring with equal counts of x and y
                }
                else
                    mp[diff] = i+1; // record the first occurrence of this diff
        }
        return ans;
    }

    int longestBalanced(string s) {

        int n = s.size(), ans = 0, fre = 0;
        vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
        for(int i=0 ; i<n ; ++i){
            a[i+1] = a[i];
            b[i+1] = b[i];
            c[i+1] = c[i];
            if(s[i] == 'a')
                ++a[i+1];
            else if(s[i] == 'b')
                ++b[i+1];
            else if(s[i] == 'c')
                ++c[i+1]; 
        }

        //CASE1 : one letter
        char letter = '-';
        for(auto &c : s){
            if(c!=letter){
                fre = 1;
                letter = c;
            }
            else
                ++fre;
            ans = max(ans, fre);
        }

        if(ans == s.size())
            return ans;

        //CASE2 : two letter
        ans = max(ans, longestPairBalanced(s, 'a', 'b', 'c'));
        ans = max(ans, longestPairBalanced(s, 'a', 'c', 'b'));
        ans = max(ans, longestPairBalanced(s, 'c', 'b', 'a'));

        //CASE3 : three letter
        map<int, vector<int>> mp;
        mp[0].emplace_back(0);
        for(int i=0 ; i<s.size() ; ++i){
            int diff = 2*a[i+1]-b[i+1]-c[i+1];
            for(auto &idx : mp[diff]){
                if((a[i+1]-a[idx] == c[i+1]-c[idx]) && (a[i+1]-a[idx] == b[i+1]-b[idx])){
                    ans = max(ans, i-idx+1); // later indices won't produce a longer substring, so break early
                    break;
                }
            }
            mp[diff].emplace_back(i+1);  
        }
        return ans;  
    }
};