class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> counts;
        int target = arr.size() / 4;
        for (int num : arr) {
            counts[num]++;
            if (counts[num] > target) {
                return num;
            }
        }

        return -1;
    }
};