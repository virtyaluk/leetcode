package main
import "math"

func angleClock(hour int, minutes int) float64 {
    hour %= 12
    ma, ha := 360.0/60.0*float64(minutes), 360.0/12.0*float64(hour) + 360.0/12.0*float64(minutes)/60.0
    a := math.Max(ma, ha) - math.Min(ma, ha)
    
    if a > 180.0 {
        return 360.0 - a
    }
    
    return a
}