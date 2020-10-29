package main
import "sort"
import "fmt"

func reconstructQueue(people [][]int) [][]int {
    sort.Slice(people, func (i, j int) bool {
        if people[i][0] == people[j][0] {
            return people[i][1] < people[j][1]
        }
        
        return people[i][0] > people[j][0]
    })
    
    ans := make([][]int, len(people))
    
    for _, person := range people {
        i := person[1]
        
        if len(ans[i]) == 0 {
            ans[i] = person
        } else {
            // for true {
            for len(person) != 0 && i < len(ans) {
                ans[i], person = person, ans[i]
                
                // if len(person) == 0 || i == len(ans) - 1 {
                //     break
                // }
                
                i++
            }
        }
    }
    
    fmt.Println(people)
    
    return ans
}