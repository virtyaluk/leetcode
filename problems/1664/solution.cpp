class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0, even = 0, odd = 0;
        vector<pair<int, int>> pre(nums.size()), suf(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
            
            pre[i] = make_pair(even, odd);
        }
        
        even = 0;
        odd = 0;
    
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
            
            suf[i] = make_pair(even, odd);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            even = pre[i].first - nums[i] + suf[i].second;
            odd = pre[i].second - nums[i] + suf[i].first;

            if (even == odd) {
                ans++;
            }
//             if (i % 2 == 0) {
//                 even = pre[i].first - nums[i] + suf[i].second;
//                 odd = pre[i].second - nums[i] + suf[i].first;
                
//                 if (even == odd) {
//                     ans++;
//                 }
                
//                 cout << i << " = " << even << " x " << odd << endl;
//             } else {
//                 even = pre[i].first - nums[i] + suf[i].second;
//                 odd = pre[i].second - nums[i] + suf[i].first;
                
//                 cout << i << " = " << even << " x " << odd << endl;
//             }
        }
        
//         for (int i = 0; i < nums.size(); i++) {
//             vector<int> nv(nums);
//             nv.erase(nv.begin() + i);
//             int even = 0, odd = 0;
            
//             for (int j = 0; j < nv.size(); j++) {
//                 if (j % 2 == 0) {
//                     even += nv[j];
//                 } else {
//                     odd += nv[j];
//                 }
//             }
            
//             if (even == odd) {
//                 ans++;
//             }
//         }
        
        return ans;
    }
};