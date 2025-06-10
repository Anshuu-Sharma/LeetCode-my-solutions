class Solution {
public:
    int maxDifference(string s) {
        sort(s.begin(),s.end());
        int n = s.size();

        int oddFreq = 0;
        int evenFreq = INT_MAX;

        int i = 0;
        while(i<n) {
            int j = i;
            int cnt = 0;
            while(j<n && s[i] == s[j]){
                cnt++;
                j++;
            }

            if(cnt%2){
                oddFreq = max(oddFreq, cnt);
            }
            else evenFreq = min(evenFreq, cnt);

            i = j;
        }

        return oddFreq-evenFreq;

    }
};