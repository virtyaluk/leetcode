class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        
        while (true) {
            if (memory2 > memory1) {
                if (time > memory2) {
                    break;
                }
                
                memory2 -= time;
            } else {
                if (time > memory1) {
                    break;
                }
                
                memory1 -= time;
            }
            
            time++;
        }
        
        return {time, memory1, memory2};
    }
};