class Solution {
public:
    string validIPAddress(string IP) {
        int dots = count(begin(IP), end(IP), '.'),
            semi = count(begin(IP), end(IP), ':');
        
        if (dots == 3 and validateIPv4(IP)) {
            return "IPv4";
        } else if (semi == 7 and validateIPv6(IP)) {
            return "IPv6";
        }
        
        return "Neither";
    }
    
    bool validateIPv4(string& s) {
        string token;
        int tokens = 0;
        istringstream iss(s);
        
        while (getline(iss, token, '.')) {
            if (empty(token) or (size(token) > 1 and token[0] == '0') or size(token) > 3) {
                return false;
            }
            
            if (size(token) != count_if(begin(token), end(token), [](const char& a){ return isdigit(a); })) {
                return false;
            }
            
            int num = stoi(token);
            
            if (num < 0 or num >= 256) {
                return false;
            }
            
            tokens++;
        }
        
        return tokens == 4;
    }
    
    bool validateIPv6(string& s) {
        int tokens = 0;
        string token;
        istringstream iss(s);

        while (getline(iss, token, ':')) {
            int validCharsCount = count_if(begin(token), end(token), [](const char& ch) {
                return (ch >= '0' and ch <= '9') or (ch >= 'a' and ch <= 'f') or (ch >= 'A' and ch <= 'F');
            });
            
            if (empty(token) or size(token) > 4 or size(token) != validCharsCount) {
                return false;
            }
            
            tokens++;
        }
        
        return tokens == 8;
    }
};