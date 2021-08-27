class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        
        return nums;
    }
    
    void mergeSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        
        vector<int> l, r;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() / 2) {
                l.push_back(nums[i]);
            } else {
                r.push_back(nums[i]);
            }
        }
        
        mergeSort(l);
        mergeSort(r);
        
        int i = 0, j = 0, k = 0;
        
        while (i < l.size() && j < r.size()) {
            if (l[i] < r[j]) {
                nums[k++] = l[i++];
            } else {
                nums[k++] = r[j++];
            }
        }
        
        while (i < l.size()) {
            nums[k++] = l[i++];
        }
        
        while (j < r.size()) {
            nums[k++] = r[j++];
        }
    }
};