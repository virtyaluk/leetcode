package main
import "strings"
import "sort"

type Fr struct {
    Ch rune
    Fr int
}

func frequencySort(s string) string {
    a, b := make([]Fr, 256), strings.Builder{}
    
    for _, v := range s {
        a[v].Ch = v
        a[v].Fr++
    }
    
    sort.Slice(a, func (i, j int) bool {
        return a[i].Fr > a[j].Fr
    })
    
    for _, v := range a {
        b.WriteString(strings.Repeat(string(v.Ch), v.Fr))
    }
    
    return b.String()
}