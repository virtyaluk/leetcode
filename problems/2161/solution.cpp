class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int count = 0;
        
        for (const int& num: nums) {
            if (num < pivot) {
                ans.push_back(num);
            }
            
            count += num == pivot;
        }
        
        while (count--) {
            ans.push_back(pivot);
        }
        
        for (const int& num: nums) {
            if (num > pivot) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};