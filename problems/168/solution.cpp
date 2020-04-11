class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        
        while (n) {
            ans.insert(ans.begin(), ((n - 1) % 26) + 'A');
            n = (n - 1) / 26;
        }
        
        return ans;
    }
};