class Solution {
public:
    string removeOccurrences(string s, string part) {
        int start_position_to_erase = s.find(part);
        if(start_position_to_erase == -1) return s;
        s.erase(start_position_to_erase, part.size());
        return removeOccurrences(s, part);
        
    }
};