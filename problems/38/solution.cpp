class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        if (n == 2) {
            return "11";
        }
        
        string curAns = countAndSay(n - 1),
            ans;
        int cnt = 1;
        
        for (int i = 1; i < size(curAns); i++) {
            if (curAns[i] != curAns[i - 1]) {
                ans.push_back('0' + cnt);
                ans.push_back(curAns[i - 1]);
                cnt = 1;
            } else {
                cnt++;
            }
            
            if (i == size(curAns) - 1) {
                ans.push_back('0' + cnt);
                ans.push_back(curAns[i]);
            }
        }
        
        return ans;
    }
};