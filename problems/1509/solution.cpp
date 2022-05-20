class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (size(nums) <= 4) {
            return 0;
        }
        
        int ans = INT_MAX;
        multiset<int> minHeap, maxHeap;
        
        for (const int& num: nums) {
            minHeap.insert(num);
            maxHeap.insert(num);
            
            if (size(minHeap) > 4) {
                minHeap.erase(prev(end(minHeap)));
                maxHeap.erase(begin(maxHeap));
            }
        }
        
        for (auto it1 = begin(minHeap), it2 = begin(maxHeap); it1 != end(minHeap); it1++, it2++) {
            ans = min(ans, *it2 - *it1);
        }
        
        return ans;
    }
    
    int minDifference1(vector<int>& nums) {
        if (size(nums) <= 4) {
            return 0;
        }
        
        int ans = INT_MAX, n = size(nums);
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < 4; i++) {
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }
        
        return ans;
    }
};