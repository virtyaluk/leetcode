class Solution {
public:
    int myAtoi(string s) {
        if (empty(s)) {
            return 0;
        }
        
        int idx = 0, n = size(s), neg = 1;
        long long int num = 0;
        unordered_set<char> sign = {'-', '+'};
        
        while (idx < n and s[idx] == ' ') {
            idx++;
        }
        
        if (idx < n and sign.count(s[idx])) {
            neg = s[idx++] == '-' ? -1 : 1;
        }
        
        while (idx < n and isdigit(s[idx])) {
            num = num * 10 + (s[idx++] - '0');
            
            if (neg == -1 and num * neg <= INT_MIN) {
                return INT_MIN;
            } else if (num > INT_MAX) {
                return INT_MAX;
            }
        }
        
        return num * neg;
    }
};