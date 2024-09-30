class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(),candies.end());
        vector<bool> answer;
        for(int it : candies)
        {
            if(it+extraCandies >= greatest) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};