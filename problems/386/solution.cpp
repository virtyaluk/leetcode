class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
        }
        
        sort(begin(ans), end(ans), [](const int& a, const int& b) {
            return to_string(a) < to_string(b);
        });
        
        return ans;
    }
};