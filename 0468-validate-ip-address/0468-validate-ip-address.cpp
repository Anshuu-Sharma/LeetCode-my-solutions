class Solution {
    bool isIPv4(const string& ip){
        if (count(ip.begin(), ip.end(), '.') != 3) return false;
        int start = 0;
        int segments = 0;
        
        for(int i = 0; i <= ip.size(); ++i) {
            if (i == ip.size() || ip[i] == '.') {
                int len = i - start;
                if(len < 1 || len > 3) return false;
                if(len > 1 && ip[start] == '0') return false;
                
                int num = 0;
                for(int j = start; j < i; ++j){
                    if(!isdigit(ip[j])) return false;
                    num = num * 10 + (ip[j] - '0');
                }
                if(num > 255) return false;
                
                start = i + 1;
                segments++;
            }
        }
        return segments == 4;
    }

    bool isIPv6(const string& ip) {
        if(count(ip.begin(), ip.end(), ':') != 7) return false;
        int start = 0;
        int segments = 0;
        
        for(int i = 0; i <= ip.size(); ++i){
            if(i == ip.size() || ip[i] == ':'){
                int len = i - start;
                if(len < 1 || len > 4) return false;
                
                for(int j = start; j < i; ++j){
                    if (!isxdigit(ip[j])) return false;
                }
                
                start = i + 1;
                segments++;
            }
        }
        return segments == 8;
    }
public:
    string validIPAddress(string queryIP) {
        if(isIPv4(queryIP)) return "IPv4";
        else if(isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};