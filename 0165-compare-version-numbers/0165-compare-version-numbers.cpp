class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = 0;
        int r = 0;
        int n1 = version1.size();
        int n2 = version2.size();

        while(l<n1 || r<n2){
            string a = "";
            string b = "";
            while(l<n1 && version1[l] != '.') {
                a+=version1[l++];
            }
            while(r<n2 && version2[r] != '.') {
                b+=version2[r++];
            }
            int num1 = a.empty() ? 0 : stoi(a);
            int num2 = b.empty() ? 0 : stoi(b);

            if(num1 > num2) return 1;
            else if(num1<num2) return -1;
            l++;
            r++;
        }

        return 0;


    }
};