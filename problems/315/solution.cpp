class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (empty(nums)) {
            return {};
        }
        
        int n = size(nums);
        vector<int> indices(n), ans(n);
        
        iota(begin(indices), end(indices), 0);
        mergeSort(nums, 0, n, indices, ans);
        
        return ans;
    }
    
    void mergeSort(const vector<int>& nums, int left, int right, vector<int>& indices, vector<int>& ans) {
        if (right - left <= 1) {
            return;
        }
        
        int mid = left + (right - left) / 2;
        
        mergeSort(nums, left, mid, indices, ans);
        mergeSort(nums, mid, right, indices, ans);
        merge(nums, left, mid, right, indices, ans);
    }
    
    void merge(const vector<int>& nums, int left, int mid, int right, vector<int>& indices, vector<int>& ans) {
        int i = left, j = mid;
        vector<int> tmp;
        
        while (i < mid and j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                tmp.push_back(indices[i]);
                ans[indices[i]] += j - mid;
                i++;
            } else {
                tmp.push_back(indices[j]);
                j++;
            }
        }
        
        while (i < mid) {
            tmp.push_back(indices[i]);
            ans[indices[i]] += j - mid;
            i++;
        }
        
        while (j < right) {
            tmp.push_back(indices[j]);
            j++;
        }
        
        for (int k = left; k < right; k++) {
            indices[k] = tmp[k - left];
        }
    }
};