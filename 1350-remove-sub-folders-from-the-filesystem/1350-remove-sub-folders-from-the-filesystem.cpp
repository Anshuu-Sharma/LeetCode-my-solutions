class Solution {
public:
    // KNK
    static bool isPrefix(const string& s, const string& b) {
        return b.size() > s.size() && b.compare(0, s.size(), s) == 0 && b[s.size()] == '/';
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> ans;
        for (const string& f : folder) {
            // If `ans` is empty or `f` is not a subfolder of the last added folder in `ans`
            if (ans.empty() || !isPrefix(ans.back(), f)) {
                ans.push_back(f);
            }
        }
        return ans;
    }

    // MYK
    // bool isPrefix(string s, string b) {
    // return b.size() >= s.size() && b.compare(0, s.size(), s) == 0;
    // }
    // void helper(vector<string>& arr, string s){
    //     for(int i = 0; i<arr.size(); i++){
    //         if(s.size() == arr[i].size() || s.size() > arr[i].size()) continue;
    //         else{
    //             if(isPrefix(s, arr[i])){
    //                 arr.erase(arr.begin() + i);
    //             }
    //         }
    //     }
    // }
    // vector<string> removeSubfolders(vector<string>& folder) {
    //     vector<string> ans;
    //     for(int i = 0; i<folder.size(); i++){
    //         helper(folder, folder[i]);
    //     }
    //     return folder;
    // }
};