class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> heapq;
        
        for (int num: A) {
            heapq.push(num);
        }
        
        while (K > 0) {
            K--;
            int num = heapq.top();
            
            heapq.pop();
            heapq.push(-num);
        }
        
        while (!heapq.empty()) {
            ans += heapq.top();
            heapq.pop();
        }
        
        return ans;
    }
};