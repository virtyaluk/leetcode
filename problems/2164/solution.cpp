class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        
        for (int i = 0; i < size(nums); i++) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        
        sort(begin(odd), end(odd), greater<>());
        sort(begin(even), end(even));
        
        for (int i = 0, j = 1; i < size(odd); i++) {
            nums[j] = odd[i];
            j += 2;
        }
        
        for (int i = 0, j = 0; i < size(even); i++) {
            nums[j] = even[i];
            j += 2;
        }
        
        return nums;
    }
};