class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans(n);
        
        iota(begin(ans), end(ans), 1);
        
        sort(begin(ans), end(ans), [&](const int& lhs, const int& rhs) {
            return helper(lhs) < helper(rhs);
        });
        
        return ans;
    }
    
    string helper(int num) {
        bitset<10> bs(num);
        string ans = bs.to_string();
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
    
    vector<int> beautifulArray1(int n) {
        vector<int> ans = {1};
        
        while (size(ans) < n) {
            vector<int> tmp;
            
            for (const int& num: ans) {
                if (num * 2 - 1 <= n) {
                    tmp.push_back(num * 2 - 1);
                }
            }
            
            for (const int& num: ans) {
                if (num * 2 <= n) {
                    tmp.push_back(num * 2);
                }
            }
            
            ans = tmp;
        }
        
        return ans;
    }
};