class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> lo, hi;
        
        for (int i = 0; i < size(nums); i++) {
            if (i >= k) {
                if (nums[i - k] <= *rbegin(lo)) {
                    lo.erase(lo.find(nums[i - k]));
                } else {
                    hi.erase(hi.find(nums[i - k]));
                }
            }
            
            lo.insert(nums[i]);
            
            hi.insert(*rbegin(lo));
            lo.erase(prev(end(lo)));
            
            if (size(lo) < size(hi)) {
                lo.insert(*begin(hi));
                hi.erase(begin(hi));
            }

            
            if (i >= k - 1) {
                if (k % 2 == 0) {
                    ans.push_back((*rbegin(lo) + *begin(hi)) * 0.5);
                } else {
                    ans.push_back(*rbegin(lo));
                }
            }
        }
        
        return ans;
    }
};