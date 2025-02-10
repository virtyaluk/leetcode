class Solution {
public:
    string removeDigit(string a, char b) {
        string ans;
    
        for (int i = 0; i < size(a); i++){
            if (a[i] == b){
                string temp = a.substr(0, i) + a.substr(i + 1);
                ans = max(ans, temp);
            }
        }
        
        return ans;
    }
};