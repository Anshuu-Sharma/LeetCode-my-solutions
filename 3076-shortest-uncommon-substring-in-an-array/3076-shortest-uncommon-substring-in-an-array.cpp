class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
                /*
        make a set and map, map will store 

        make all substrings for arr[i], 
        cab: c(X),a(X),b(X),ca,ab
        ad: a(X),d
        bad: b(X),a(X),d(X),ba,ad
        c: c(X)

        all marked as (X) cant be our answer
        
        */
        //We just want to know  in how many index a particular substring is presnt .
        //->for this purpose i used map where key is substring and count tells in how many arr[i] this substring is present
        // if mp[val]==1 then its valid substring 
        
        unordered_map<string,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            unordered_set<string>st;// to remove duplicate substr in same i
            for(int j=0;j<arr[i].size();j++)
            {
                string temp;
                for(int k=j;k<arr[i].size();k++)
                {
                    temp+=arr[i][k];
                    st.insert(temp);
                }
            }
            for(auto it:st)mp[it]++; //set will insure only one occurance of substr is present
        }
        vector<string>ans;
        for(int i=0;i<arr.size();i++)
        {
            string res; 
            for(int j=0;j<arr[i].size();j++)
            {
                string temp;
                for(int k=j;k<arr[i].size();k++)
                {
                    temp+=arr[i][k];
                    if(mp[temp]==1)
                    {
                        if(res.size()==0)res=temp;
                        else {
                            if(temp.size()<res.size())res=temp;
                            else if(res.size()==temp.size())res=min(res,temp);
                        }
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};