package main
type Solution struct {
    r, xc, yc float64
}


func Constructor(radius float64, x_center float64, y_center float64) Solution {
    return Solution{radius, x_center, y_center}
}


func (this *Solution) RandPoint() []float64 {
    r, theta := this.r * math.Sqrt(rand.Float64()), math.Pi * 2 * rand.Float64()
    x, y := r * math.Cos(theta) + this.xc, r * math.Sin(theta) + this.yc
    
    return []float64{x, y}
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(radius, x_center, y_center);
 * param_1 := obj.RandPoint();
 */