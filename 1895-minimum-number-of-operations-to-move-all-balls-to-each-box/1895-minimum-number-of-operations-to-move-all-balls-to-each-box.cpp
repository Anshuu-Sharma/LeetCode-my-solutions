class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        for(int i = 0; i<boxes.size(); i++)
        {
            int cnt = 0;
            for(int j = 0; j<boxes.size(); j++){
                if(boxes[j] == '1'){
                    cnt+=abs(j-i);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};