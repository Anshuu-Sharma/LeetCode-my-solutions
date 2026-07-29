class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();

        if(num1=="0"||num2=="0")
            return "0";

        vector<int> num(n1+n2,0);

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){

                num[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');

                num[i+j]+=num[i+j+1]/10;

                num[i+j+1]%=10;
            }
        }

        int i=0;

        while(i<num.size() && num[i]==0)
            i++;

        string res;

        while(i<num.size())
            res.push_back(num[i++]+'0');

        return res;
    }
};