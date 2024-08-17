class Solution {
public:
    string defangIPaddr(string address) {
      string defanged = "";
        for(int i = 0; i<address.size(); i++) {
            if(address[i] == '.') {
                defanged += "[.]";
            } else {
                defanged += address[i];
            }
        }
        return defanged;
    }
};