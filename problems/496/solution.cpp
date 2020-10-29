class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> um;
        stack<int> st;
        
        for (const int& num: nums2) {
            while (not empty(st) and st.top() <= num) {
                um[st.top()] = num;
                st.pop();
            }
            
            st.push(num);
        }
        
        for (const int& num: nums1) {
            ans.push_back(um.count(num) ? um[num] : -1);
        }
        
        return ans;
    }
};