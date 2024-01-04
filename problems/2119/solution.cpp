class Solution {
public:
    bool isSameAfterReversals(int num) {
        string snum = to_string(num);
        int num2;
        
        reverse(begin(snum), end(snum));
        
        num2 = stoi(snum);
        snum = to_string(num2);
        
        reverse(begin(snum), end(snum));
        
        num2 = stoi(snum);
        
        return num == num2;
    }
};