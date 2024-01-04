class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        
        for (int i = 1; i < size(colors) - 1; i++) {
            if (colors[i - 1] == colors[i] and colors[i + 1] == colors[i]) {
                a += colors[i] == 'A';
                b += colors[i] == 'B';
            }
        }
        
        return a - b >= 1;
    }
};