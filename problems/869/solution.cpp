class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> num = getNum(N);
        
        for (int i = 0; i < 31; i++) {
            int powOf2 = pow(2, i);
            
            if (N == powOf2 or num == getNum(powOf2)) {
                return true;
            }
        }
        
        return false;
    }
    
    vector<int> getNum(int n) {
        vector<int> ans(10);
        
        for (char ch: to_string(n)) {
            ans[ch - '0']++;
        }
        
        return ans;
    }
};