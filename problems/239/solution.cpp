class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> heap;
        
        for (int i = 0; i < size(nums); i++) {
            if (i >= k) {
                heap.erase(heap.find(nums[i - k]));
            }
            
            heap.insert(nums[i]);
            
            if (i >= k - 1) {
                ans.push_back(*prev(end(heap)));
            }
        }
        
        return ans;
    }
};