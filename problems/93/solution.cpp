class Solution {
private:
    bool check(string& s) {
        if (size(s) == 1) {
            return true;
        }
        
        if (size(s) > 3 or s.front() == '0') {
            return false;
        }
        
        if (stoi(s) > 255) {
            return false;
        }
        
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = size(s);
        
        if (n > 12) {
            return ans;
        }
        
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i + j + k < n and i + j + k + 3 >= n) {
                        string a = s.substr(0, i),
                            b = s.substr(i, j),
                            c = s.substr(i + j, k),
                            d = s.substr(i + j + k);

                        if (check(a) and check(b) and check(c) and check(d)) {
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};