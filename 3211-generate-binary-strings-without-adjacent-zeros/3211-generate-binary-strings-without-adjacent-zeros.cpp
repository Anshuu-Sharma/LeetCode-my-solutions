class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string current = "";
        generate(current, n, result);
        return result;
    }
    
private:
    // Notice the '&' - we are now passing 'current' by reference
    void generate(string& current, int n, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        
        // Option 1: Append '1'
        current.push_back('1');       // Make the choice
        generate(current, n, result); // Explore
        current.pop_back();           // Undo the choice (backtrack)
        
        // Option 2: Append '0'
        if (current.empty() || current.back() != '0') {
            current.push_back('0');       // Make the choice
            generate(current, n, result); // Explore
            current.pop_back();           // Undo the choice (backtrack)
        }
    }
};