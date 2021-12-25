class Solution {
public:
    vector<int> sequentialDigits1(int low, int high) {
        vector<int> ans;
        string sample = "123456789";
        int lowLen = to_string(low).size(), highLen = to_string(high).size();
        
        for (int len = lowLen; len < highLen + 1; len++) {
            for (int start = 0; start < 10 - len; start++) {
                int num = stoi(sample.substr(start, len));
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        
        return ans;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        
        for (int i = 1; i < 10; i++) {
            q.push(i);
        }
        
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            
            if (num >= low) {
                ans.push_back(num);
            }
            
            int d = num % 10 + 1;
            
            if (d <= 9 && num * 10 + d <= high) {
                q.push(num * 10 + d);
            }
        }
        
        return ans;
    }
};