class Solution {
public:
    int connectSticks1(vector<int>& sticks) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (const int& stick: sticks) {
            pq.push(stick);
        }
        
        while (pq.size() > 1) {
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            
            ans += one + two;
            pq.push(one + two);
        }
        
        return ans;
    }
    
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        
        make_heap(begin(sticks), end(sticks), greater<>());
        
        while (size(sticks) > 1) {
            pop_heap(begin(sticks), end(sticks), greater<>());
            
            int x = sticks.back();
            sticks.pop_back();
            
            pop_heap(begin(sticks), end(sticks), greater<>());
            
            int y = sticks.back();
            sticks.pop_back();
            
            ans += x + y;
            
            sticks.push_back(x + y);
            push_heap(begin(sticks), end(sticks), greater<>());
        }
        
        return ans;
    }
};