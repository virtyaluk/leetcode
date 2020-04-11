/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int pos = 0, lastRead = 4;
        char buf4[4];
        
        while (pos < n and lastRead == 4) {
            lastRead = read4(buf4);
            
            for (int i = 0; i < lastRead; i++) {
                if (pos == n) {
                    return pos;
                }
                
                buf[pos++] = buf4[i];
            }
        }
        
        return pos;
    }
};