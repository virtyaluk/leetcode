typedef long long int ll;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target.back() == 1;
        }
        
        ll sum = 0;
        priority_queue<ll> pq;
        
        for (const int& num: target) {
            sum += num;
            pq.push(num);
        }
        
        while (pq.top() > 1) {
            ll cur = pq.top();
            pq.pop();
            
            ll rest = sum - cur;
            
            if (rest == 1) {
                return true;
            }
            
            ll prev = cur % rest;
            
            if (prev == 0 or prev == cur) {
                return false;
            }
            
            pq.push(prev);
            sum = sum - cur + prev;
        }
        
        return true;
    }
};