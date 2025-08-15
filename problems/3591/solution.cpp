class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        unordered_map<int, int> freq;

        for (const int& num: nums) {
            freq[num]++;
        }

        for (auto& [_, cnt]: freq) {
            if (primes.count(cnt)) {
                return true;
            }
        }

        return false;
    }
};