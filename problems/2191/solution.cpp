class Solution {
private:
    int transform(map<int, int>& m, vector<int>& mapping, int num) {
        if (not m.count(num)) {
            string snum = to_string(num);
            
            
            for (char& ch: snum) {
                ch = '0' + mapping[ch - '0'];
            }
            
            m[num] = stoi(snum);
        }
        
        return m[num];
    }
    
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, int> m;
        
        sort(begin(nums), end(nums), [&](const int& a, const int& b) {
            return transform(m, mapping, a) < transform(m, mapping, b);
        });
        
        return nums;
    }
};