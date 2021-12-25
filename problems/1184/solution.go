package main
func distanceBetweenBusStops(distance []int, start int, destination int) int {
    back, forth := 0, 0
    
    if destination < start {
        destination, start = start, destination
    }
    
    for i, d := range distance {
        if i >= start && i < destination {
            forth += d
        } else {
            back += d
        }
    }
    
    if back < forth {
        return back
    }
    
    return forth
}