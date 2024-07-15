class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> us;
        
        for (int num: nums) {
            us.insert(num);
            string snum = to_string(num);
            
            reverse(begin(snum), end(snum));
            
            us.insert(stoi(snum));
        }
        
        return size(us);
    }
};