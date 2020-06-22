class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
        
        for (int num: nums) {
            if (num == num1) {
                cnt1++;
                continue;
            }
            
            if (num == num2) {
                cnt2++;
                continue;
            }
            
            if (cnt1 == 0) {
                num1 = num;
                cnt1++;
                continue;
            }
            
            if (cnt2 == 0) {
                num2 = num;
                cnt2++;
                continue;
            }
            
            cnt1--;
            cnt2--;
        }
        
        cnt1 = 0;
        cnt2 = 0;
        
        for (int num: nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            }
        }
        
        if (cnt1 > nums.size() / 3) {
            ans.push_back(num1);
        }
        
        if (cnt2 > nums.size() / 3) {
            ans.push_back(num2);
        }
        
        return ans;
    }
};