class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1{nums[0]},
            arr2{nums[1]};
        
        for (int i = 2; i < size(nums); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        for (const int& num: arr2) {
            arr1.push_back(num);
        }
        
        return arr1;
    }
};