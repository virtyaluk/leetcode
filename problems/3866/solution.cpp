class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> um;

        for (const int& num: nums) {
            um[num]++;
        }

        for (const int& num: nums) {
            if (num % 2 == 0 and um[num] == 1) {
                return num;
            }
        }

        return -1;
    }
};