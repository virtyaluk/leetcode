class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
//         vector<bool> ans;
        
//         for (int i = 1; i < nums.size(); i++) {
//             ans.push_back(nums[i - 1] - nums[i] >= 0);
//         }
        
        // copy(begin(ans), end(ans), ostream_iterator<bool>(cout, " "));
        // cout << endl;
        
        bool start1 = true, start2 = false;
        int count1 = 1, count2 = 1;
        
        // for (const bool& val: ans) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                continue;
            }
            
            bool val = nums[i - 1] - nums[i] > 0;
            cout << val << " ";

            if (start1 == not val) {
                count1++;
                start1 = val;
            }
            
            if (start2 == not val) {
                count2++;
                start2 = val;
            }
        }
        cout << endl;
        
        return max(count1, count2);
    }
};