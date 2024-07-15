class Solution {
private:
    int solve(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            if (i and nums[i] != i) {
                nums.front() = nums[i];
                nums[i] = 0;
                ans++;
            }
            
            while (nums[0] != 0) {
                int pos = nums[0];
                swap(nums[0], nums[pos]);
                ans++;
            }
        }
        
        return ans;
    }
public:
    int sortArray(vector<int>& nums) {
        vector<int> nums2;
        
        nums2.push_back(nums.back());
        nums2.insert(end(nums2), begin(nums), begin(nums) + size(nums) - 1);
        
        return min(solve(nums), solve(nums2));
    }
};