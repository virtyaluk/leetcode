class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long int ans = 0;
        vector<int> dif;
        
        for (int i = 0; i < size(nums1); i++) {
            dif.push_back(nums1[i] - nums2[i]);
        }
        
        sort(begin(dif), end(dif));
        
        // copy(begin(dif), end(dif), ostream_iterator<int>(cout, ", "));
        // cout << endl;
        
        for (int lo = 0, hi = size(dif) - 1; lo < hi;) {
            if (dif[lo] + dif[hi] > 0) {
                ans += hi - lo;
                hi--;
            } else {
                lo++;
            }
        }
        
        return ans;
    }
};