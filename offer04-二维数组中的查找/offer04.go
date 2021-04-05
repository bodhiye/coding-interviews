package main

import "fmt"

func main() {
	var matrix = [][]int{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	}

	fmt.Println(findNumberIn2DArray(matrix, 5))
	fmt.Println(findNumberIn2DArray(matrix, 20))
}

func findNumberIn2DArray(matrix [][]int, target int) bool {
	if matrix == nil || len(matrix) <= 0 || len(matrix[0]) <= 0 {
		return false
	}

	n, m := len(matrix), len(matrix[0])
	for i, j := 0, m-1; i < n && j >= 0; {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] < target {
			i++
		} else {
			j--
		}
	}

	return false
}
