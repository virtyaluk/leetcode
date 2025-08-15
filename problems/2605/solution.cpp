class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int m1 = INT_MAX,
            m2 = INT_MAX,
            m3 = INT_MAX;
        unordered_map<int, int> um;

        for (const int& num: nums1) {
            m1 = min(m1, num);
            um[num]++;
        }

        for (const int& num: nums2) {
            m2 = min(m2, num);
            um[num]++;

            if (um[num] == 2) {
                m3 = min(m3, num);
            }
        }

        return min(m3, m1 < m2 ? m1 * 10 + m2 : m2 * 10 + m1);
    }
};