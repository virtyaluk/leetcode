class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        
        for (int i = 1; i <= num; i++) {
            // if (i % 2 == 0) {
            //     ans[i] = ans[i / 2];
            // } else {
            //     ans[i] = ans[i / 2] + 1;
            // }
            ans[i] = ans[i / 2] + i % 2;
        }
        
        return ans;
    }
    
    vector<int> countBits1(int num) {
        vector<int> ans(num + 1);
        
        for (int i = 1; i <= num; i++) {
            ans[i] = popcount(i);
        }
        
        return ans;
    }
    
    int popcount(int num) {
        int ans = 0;
        
        while (num) {
            ans++;
            num = num & num - 1;
        }
        
        // for (int i = 0; i < 32; i++) {
        //     if ((num & (1 << i)) != 0) {
        //         ans++;
        //     }
        // }
        
        return ans;
    }
};