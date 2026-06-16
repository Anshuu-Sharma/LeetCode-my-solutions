class Solution {
public:
    int numDecodings(string s) {

        if(s.length()==0 || s[0]=='0'){
            return 0;
        }

        int prevCount = 1; 
        int prevToPrevCount = 1; 
        for(int i=1;i<s.length();i++){
            int currentCount = 0; 
            if(s[i]!='0'){
                currentCount = prevCount;
            }
            int twoDigit = stoi(s.substr(i-1,2));
            if(twoDigit>=10 && twoDigit<=26){
                currentCount+=prevToPrevCount;
            }
            prevToPrevCount = prevCount;
            prevCount = currentCount; 
        }
        return prevCount; 
    }
};