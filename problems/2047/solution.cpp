class Solution {
private:
    bool isValidWord(const string& word) {
        int n = word.size();
        bool hasHyphen = false,
            hasPunctuation = false;
        
        for (int i = 0; i < n; i++) {
            if (isdigit(word[i])) {
                return false;
            }

            if (word[i] == '-') {
                if (hasHyphen or i == 0 or i == n - 1 or !islower(word[i-1]) or !islower(word[i+1])) {
                    return false;
                }

                hasHyphen = true;
            }

            if (word[i] == '!' or word[i] == '.' or word[i] == ',') {
                if (hasPunctuation or i != n - 1) {
                    return false;
                }

                hasPunctuation = true;
            }
        }
        
        return true;
    }
public:
    int countValidWords(string sentence) {
        istringstream ss(sentence);
        string token;
        int ans = 0;
        
        while (ss >> token) {
            ans += isValidWord(token);
        }
        
        return ans;
    }
};