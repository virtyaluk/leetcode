class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (const int& num: arr) {
            um[num]++;
        }
        
        for (auto [_, cnt]: um) {
            pq.push(cnt);
        }
        
        while (k > 0) {
            k -= pq.top();
            
            if (k >= 0) {
                pq.pop();
            }
        }
        
        return size(pq);
    }
};