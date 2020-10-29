package main
func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2) {
        return false
    }
    
    s1ar, s2ar, count := make([]int, 26), make([]int, 26), 0
    
    for i, ch := range s1 {
        s1ar[ch - 'a']++
        s2ar[s2[i] - 'a']++
    }
    
    for i, _ := range s1ar {
        if s1ar[i] == s2ar[i] {
            count++
        }
    }
    
    for i := 0; i < len(s2) - len(s1); i++ {
        if count == 26 {
            return true
        }
        
        left, right := s2[i] - 'a', s2[i + len(s1)] - 'a'
        
        s2ar[right]++
        
        if s1ar[right] == s2ar[right] {
            count++
        } else if s1ar[right] + 1 == s2ar[right] {
            count--
        }
        
        s2ar[left]--
        
        if s1ar[left] == s2ar[left] {
            count++
        } else if s1ar[left] - 1 == s2ar[left] {
            count--
        }
    }
    
    return count == 26
}