class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[hi],
            startIdx = lo;
        
        for (int i = lo; i < hi; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[startIdx]);
                startIdx++;
            }
        }
        
        swap(nums[startIdx], nums[hi]);
        
        return startIdx;
    }
    
    void quickselect(vector<int>& nums, int lo, int hi, int k) {
        while (lo <= hi) {
            int mid = partition(nums, lo, hi);
            
            if (mid == k) {
                return;
            } else if (mid < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = size(nums);
        
        quickselect(nums, 0, n - 1, n - k);
        
        return nums[n - k];
    }
    
    int findKthLarges3(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + k, end(nums), greater());
        
        return nums[k - 1];
    }
    
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (const int& num: nums) {
            pq.push(num);
            
            if (size(pq) > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater());
        
        return nums[k - 1];
    }
};