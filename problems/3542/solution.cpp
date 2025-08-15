class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> st;

        for (const int& num: nums) {
            while (not empty(st) and st.back() > num) {
                st.pop_back();
            }

            if (num and (empty(st) or st.back() < num)) {
                ans++;
                st.push_back(num);
            }
        }

        return ans;
    }
};