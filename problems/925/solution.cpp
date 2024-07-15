class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0,
            j = 0;
        
        while (j < size(typed)) {
            if (i < size(name) and name[i] == typed[j]) {
                i++;
                j++;
            } else if (i > 0 and name[i - 1] == typed[j]) {
                j++;
            } else {
                return false;
            }
        }
        
        return i == size(name);
    }
};