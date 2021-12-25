class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> m;
        
        // cout << "*********" << endl;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] != nums[j]) {
                    m[nums[i] * nums[j]]++;
                }
            }
        }
        
        for (auto [k, v]: m) {
            // cout << k << " = " << v << endl;
            
            ans += nChoosek(v, 2) * 8;
        }
        
        return ans;
    }
    
    unsigned nChoosek(unsigned n, unsigned k){
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
};