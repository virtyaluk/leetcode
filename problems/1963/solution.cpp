class Solution {
public:
    int minSwaps(string s) {
        int ans = 0,
            n = size(s),
            balance = 0,
            j = n - 1;
        
        for (int i = 0; i < n; i++) {
            balance += s[i] == '[' ? 1 : -1;
            
            if (balance < 0) {
                while (i < j and s[j] != '[') {
                    j--;
                }
                
                swap(s[i], s[j]);
                ans++;
                balance = 1;
            }
        }
        
        return ans;
    }
};