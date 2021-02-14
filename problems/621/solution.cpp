class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        
        // frequency of each task
        for (const char& ch: tasks) {
            freq[ch - 'A']++;
        }
        
        // Find the maximum frequency
        int maxTask = *max_element(begin(freq), end(freq));
        // number of tasks which have the max frequency
        int countMaxTasks = count(begin(freq), end(freq), maxTask);
        
        return max((int) tasks.size(), (n + 1) * (maxTask - 1) + countMaxTasks);
    }
    
    int leastInterval1(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> freqs(26);
        priority_queue<int> pq;
        
        for (const char& ch: tasks) {
            freqs[ch - 'A']++;
        }
        
        for (const int& freq: freqs) {
            if (freq) {
                pq.push(freq);
            }
        }
        
        while (not pq.empty()) {
            int cycle = n + 1;
            vector<int> tmp;
            
            for (int i = 0; i < cycle; i++) {
                if (not pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                }
            }
            
            for (int& duration: tmp) {
                if (--duration) {
                    pq.push(duration);
                }
            }
            
            ans += pq.empty() ? tmp.size() : cycle;
        }
        
        return ans;
    }
};