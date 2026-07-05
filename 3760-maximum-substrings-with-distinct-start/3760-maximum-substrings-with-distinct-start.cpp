class Solution {
public:
    int maxDistinct(string s) {
       int r[26]={0};
        int count=0;
        for(char ch:s){
            r[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(r[i]!=0)
              count++;
        }
        return count;
    }
};