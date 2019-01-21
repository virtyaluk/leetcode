func canJump(nums []int) bool {
    leftmostGoodIndex := len(nums) - 1
    
    for currentPosition := len(nums) - 2; currentPosition >= 0; currentPosition-- {
        if currentPosition + nums[currentPosition] >= leftmostGoodIndex {
            leftmostGoodIndex = currentPosition
        }
    }
    
    return leftmostGoodIndex == 0
}