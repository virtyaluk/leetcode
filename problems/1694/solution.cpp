class Solution {
public:
    string reformatNumber(string number) {
        cout << "********" << endl;
        
        string ans = "";
        
        if (number.empty()) {
            return ans;
        }
        
        string str = "";
        
        for (char& ch: number) {
            if (isdigit(ch)) {
                str += ch;
            }
        }
        
        int n = str.size(), sub = n == 4 ? 2 : 3;
        
        for (int i = 0; i < n;) {
            ans += str.substr(i, sub) + "-";
            i += sub;
            
            int left = n - i;
            
            if (left == 4) {
                sub = 2;
            }
        }
        
        return ans.substr(0, ans.size() - 1);
    }
};