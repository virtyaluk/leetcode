package main
func topKFrequent(nums []int, k int) []int {
    m, buckets, flatList := map[int]int{}, make([][]int, len(nums) + 1), []int{}
    
    for _, num := range nums {
        m[num]++
    }
    
    for val, freq := range m {
        buckets[freq] = append(buckets[freq], val)
    }
    
    for _, bucket := range buckets {
        if len(bucket) == 0 {
            continue
        }
        
        flatList = append(flatList, bucket...)
    }
    
    reverse(flatList)
    
    return flatList[:k]
}

func reverse(ar []int) {
    lo, hi := 0, len(ar) - 1
    
    for lo < hi {
        ar[lo], ar[hi] = ar[hi], ar[lo]
        lo++
        hi--
    }
}