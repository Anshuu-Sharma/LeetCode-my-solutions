class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++, freq[t[i]-'a']--;
        }
        
        int cnt = 0;
        for(auto x : freq) if(x>0) cnt+=x;
        return cnt;
    }
};