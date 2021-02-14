class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (int i = 0; i < size(arr) - 1; i++) {
            pq.push({-1.0 * arr[i] / arr.back(), {i, size(arr) -  1}});
        }
        
        while (--k > 0) {
            auto [i, j] = pq.top().second;
            pq.pop();
            
            j--;
            
            pq.push({-1.0 * arr[i] / arr[j], {i, j}});
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};