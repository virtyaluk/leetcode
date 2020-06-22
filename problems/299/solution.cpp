class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> a, b;
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                a[secret[i]]++;
                b[guess[i]]++;
            }
        }
        
        for (auto &[ch, freq]: a) {
            cows += min(freq, b[ch]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};