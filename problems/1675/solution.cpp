class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, m = INT_MAX;
        priority_queue<int> q;
        
        for (const int& num: nums) {
            if (num % 2 == 0) {
                q.push(num);
                m = min(m, num);
            } else {
                q.push(num * 2);
                m = min(m, num * 2);
            }
        }
        
        while (!q.empty()) {
            int num = q.top();
            q.pop();
            
            ans = min(ans, num - m);
            
            if (num % 2 == 0) {
                q.push(num / 2);
                m = min(m, num / 2);
            } else {
                break;
            }
        }
        
        return ans;
    }
};