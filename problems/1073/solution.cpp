class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i = size(arr1) - 1, j = size(arr2) - 1, carry = 0;
        
        while (i >= 0 or j >= 0 or carry != 0) {
            if (i >= 0) {
                carry += arr1[i--];
            }
            
            if (j >= 0) {
                carry += arr2[j--];
            }
            
            ans.push_back(abs(carry) % 2);
            carry = carry < 0 ? 1 : carry <= 1 ? 0 : -1;
        }
        
        while (size(ans) > 1 and ans.back() == 0) {
            ans.pop_back();
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};