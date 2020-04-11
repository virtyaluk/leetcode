/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char buf4[4];
    int lastRead4Len = 0,
        read4Pos = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int pos = 0;
        
        while (pos < n) {
            if (lastRead4Len == read4Pos) {
                read4Pos = 0;
                lastRead4Len = read4(buf4);
                
                if (lastRead4Len == 0) {
                    break;
                }
            }
            
            buf[pos++] = buf4[read4Pos++];
        }
        
        return pos;
    }
};