class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dif = 0, a = 0, b = 0;
        
        for (const int& num: nums) {
            dif ^= num;
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            dif ^= i;
        }
        
        dif = dif & -dif;
        
        for (const int& num: nums) {
            if (dif & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (dif & i) {
                a ^= i;
            } else {
                b ^= i;
            }
        }
        
        for (const int& num: nums) {
            if (num == b) {
                return {b, a};
            }
        }
        
        return {a, b};
    }
    
    vector<int> findErrorNums2(vector<int>& nums) {
        vector<int> ans(2);
        
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            
            if (nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            } else {
                ans[0] = num;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[1] = i + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> findErrorNums1(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for (const int& num: nums) {
            m[num]++;
            
            if (m[num] >= 2) {
                ans.push_back(num);
            }
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (not m.count(i)) {
                ans.push_back(i);
                break;
            }
        }
        
        return ans;
    }
};