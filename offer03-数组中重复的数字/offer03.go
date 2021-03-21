package main

import "fmt"

func main() {
	var nums = []int{2, 3, 1, 0, 2, 5, 3}
	fmt.Println(findRepeatNumber(nums))
	fmt.Println(findRepeatNumber2(nums))
}

func findRepeatNumber(nums []int) int {
	var m = make(map[int]bool, len(nums))
	for _, num := range nums {
		if m[num] {
			return num
		}
		m[num] = true
	}
	return 0
}

// 原地置换法
func findRepeatNumber2(nums []int) int {
	for i, num := range nums {
		for nums[i] != i {
			if nums[i] == num {
				return nums[i]
			}
			nums[i], num = num, nums[i]
		}
	}
	return 0
}
