#define ll long long int

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        ll ans = INT_MAX;
        vector<ll> workers(k);
        
        sort(jobs.begin(), jobs.end(), greater<ll>());
        
        function<void(int)> bt;
        
        bt = [&](int i) {
            if (i == jobs.size()) {
                ans = *max_element(workers.begin(), workers.end());
            } else {
                for (int j = 0; j < k; j++) {
                    if (j == 0 || workers[j - 1] > workers[j]) {
                        workers[j] += jobs[i];
                        
                        if (*max_element(workers.begin(), workers.end()) < ans) {
                            bt(i + 1);
                        }
                        
                        workers[j] -= jobs[i];
                    }
                }
            }
        };
        
        bt(0);
        
        return ans;
    }
};