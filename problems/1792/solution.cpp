class Solution {
private:
    double calcGain(int pass, int total) {
        return (double) (pass + 1) / (total + 1) - (double) pass / total;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        priority_queue<tuple<double, int, int>> pq;
        
        for (const vector<int>& c: classes) {
            pq.push({calcGain(c.front(), c.back()), c.front(), c.back()});
        }
        
        while (extraStudents--) {
            auto [gain, pass, total] = pq.top();
            pq.pop();
            pq.push({calcGain(pass + 1, total + 1), pass + 1, total + 1});
        }
        
        while (not empty(pq)) {
            auto [_, pass, total] = pq.top();
            pq.pop();
            
            ans += (double) pass / total;
        }
        
        return ans / size(classes);
    }
};