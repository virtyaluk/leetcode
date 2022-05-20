class Encrypter {
private:
    unordered_map<string, int> decrypted;
    unordered_map<char, string> keyToVal;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < size(keys); i++) {
            keyToVal[keys[i]] = values[i];
        }
        
        for (const string& word: dictionary) {
            string encrypted = encrypt(word);
            
            decrypted[encrypted]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        
        for (const char& ch: word1) {
            if (not keyToVal.count(ch)) {
                return "";
            }
            
            ans += keyToVal[ch];
        }
        
        return ans;
    }
    
    int decrypt(string word2) {
        return decrypted[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */