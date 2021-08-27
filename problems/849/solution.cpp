class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDist = 0;
        
        while (seats[maxDist] == 0) {
            maxDist++;
        }
        
        for (int i = maxDist; i < seats.size(); i++) {
            if (!seats[i]) {
                continue;
            }
            
            int j = i;
                
            while (i + 1 < seats.size() && seats[i + 1] != 1) {
                i++;
            }

            if (i == seats.size() - 1 && i - j > maxDist) {
                maxDist = i - j;
            } else if ((i - j + 1) / 2 > maxDist) {
                maxDist = (i - j + 1) / 2;
            }
        }
        
        return maxDist;
    }
};