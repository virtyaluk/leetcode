class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            ans[i] += k > 25 ? 25 : k;
            k -= k > 25 ? 25 : k;
        }
        
        return ans;
    }
};