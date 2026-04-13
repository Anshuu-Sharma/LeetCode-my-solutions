class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> hash(26,0);
        for(auto it: tiles){
            hash[it-'A']++;
        }

        return helper(hash);
    }
private:
    int helper(vector<int>& hash){
        int sum = 0;

        for(int i = 0; i<26; i++){
            if(hash[i] == 0) continue;

            sum++;

            hash[i]--;
            sum += helper(hash);

            hash[i]++;
        }

        return sum;
    }
};