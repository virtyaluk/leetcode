struct CompareStrNums {
    inline bool operator() (int a, int b) {
        string as = to_string(a), bs = to_string(b);
        
        return bs + as < as + bs;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        
        sort(nums.begin(), nums.end(), CompareStrNums());
        
        for (int num: nums) {
            cout << num << endl;
            ans += to_string(num);
        }
        
        if (nums.front() == 0) {
            return "0";
        }
        
        return ans;
    }
};