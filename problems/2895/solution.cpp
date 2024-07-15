class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int ans = 0;
        
        sort(begin(processorTime), end(processorTime));
        sort(begin(tasks), end(tasks), greater<>());
        
        for (int i = 0, cpuTime = 0; i < size(tasks); i += 4) {
            cpuTime = processorTime[i / 4];
            ans = max({
                ans,
                cpuTime + tasks[i],
                cpuTime + tasks[i + 1],
                cpuTime + tasks[i + 2],
                cpuTime + tasks[i + 3]
            });
        }
        
        return ans;
    }
};