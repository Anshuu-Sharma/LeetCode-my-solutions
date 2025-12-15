class Solution {
public:
    int freq_counter(string s){
        int n = s.size();
        int ans = 1;
        sort(s.begin(), s.end());

        int i = 1;
        while(i<n){
            if(s[i-1] == s[i]){
                ans++;
            }
            else break;
            i++;
        }
        return ans;
    }

    int bs(vector<int>& freq_words, int x){
        int n = freq_words.size();
        int low = 0;
        int high = n-1;

        int ans_ind = n;
        while(low<=high){
            int mid = (low+high)/2; 
            if(freq_words[mid] > x){
                ans_ind = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return n - ans_ind;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        int m = queries.size();


        vector<int> freq_words;
        for(int i = 0; i<n; i++) {
            freq_words.push_back(freq_counter(words[i]));
        }

        sort(freq_words.begin(),freq_words.end());
        vector<int> ans;
        for(int i = 0; i<m; i++) {
            int x = bs(freq_words, freq_counter(queries[i]));
            ans.push_back(x);
        }
        return ans;
    }
};