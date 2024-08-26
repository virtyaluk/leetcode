class Solution {
public:
    int largestInteger(int num) {
        string snum = to_string(num),
            ans;
        vector<vector<int>> digits(2);
        
        while (num) {
            int d = num % 10;
            
            digits[d % 2].push_back(d);
            
            num /= 10;
        }
        
        sort(begin(digits[0]), end(digits[0]));
        sort(begin(digits[1]), end(digits[1]));
        
        for (char& ch: snum) {
            int d = ch - '0';
            
            ch = '0' + digits[d % 2].back();
            digits[d % 2].pop_back();
        }
        
        return stoi(snum);
    }
};