func romanToInt(s string) int {
    mapping := map[rune]uint16 {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    var sum uint16 = 0
    
    for i, v := range s {
        if i != 0 && mapping[rune(s[i - 1])] < mapping[v] {
            sum -= 2 * mapping[rune(s[i - 1])]
        }
        
        sum += mapping[v]
    }
    
    return int(sum)
}