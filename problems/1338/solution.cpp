class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0, n = size(arr), removed = 0, maxNum = INT_MIN;
        unordered_map<int, int> freqs;
        
        for (const int& num: arr) {
            freqs[num]++;
            maxNum = max(maxNum, freqs[num]);
        }
        
        vector<int> buckets(maxNum + 1);
        
        for (auto [ignore, freq]: freqs) {
            buckets[freq]++;
        }
        
        for (int i = maxNum; i >= 0 and removed < n / 2;) {
            if (buckets[i] == 0) {
                i--;
                continue;
            }
            
            buckets[i]--;
            removed += i;
            ans++;
        }
        
        return ans;
    }
    
    int minSetSize1(vector<int>& arr) {
        int ans = 0, n = size(arr), removed = 0;
        unordered_map<int, int> freqs;
        priority_queue<int> pq;
        
        for (const int& num: arr) {
            freqs[num]++;
        }
        
        for (auto [ignore, freq]: freqs) {
            pq.push(freq);
        }
        
        while (not empty(pq) and removed < n / 2) {
            removed += pq.top();
            pq.pop();
            
            ans++;
        }
        
        return ans;
    }
};