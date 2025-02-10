class Solution {
public:
    bool sumGame(string num) {
        int sum = 0,
            a = 0,
            b = 0;
        
        for (int i = 0; i < size(num); i++) {
            if (i < size(num) / 2) {
                if (num[i] == '?') {
                    a++;
                } else {
                    sum += num[i] - '0';   
                }
            } else {
                if (num[i] == '?') {
                    b++;
                } else {
                    sum -= num[i] - '0';
                }
            }
        }
        
        if ((a + b) % 2 == 1) {
            return true;
        }
        
        
        
        return sum + (a / 2 ) * 9 - (b / 2) * 9;
    }
};