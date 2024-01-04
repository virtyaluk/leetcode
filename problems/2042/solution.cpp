class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> nums;
        stringstream ss(s);
        string token;
        
        while (getline(ss, token, ' ')) {
            if (isdigit(token.front())) {
                nums.push_back(stoi(token));
            }
        }
        
        return is_sorted(begin(nums), end(nums)) and unique(begin(nums), end(nums)) == end(nums);
    }
};