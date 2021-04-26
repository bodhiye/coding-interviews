package main

import "fmt"

func main() {
	matrix := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	matrix1 := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	fmt.Println(spiralOrder(matrix))
	fmt.Println(spiralOrder(matrix1))
	fmt.Println(spiralOrder1(matrix))
	fmt.Println(spiralOrder1(matrix1))
}

func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return nil
	}
	m, n := len(matrix), len(matrix[0])
	visited := make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	var (
		ret       = make([]int, m*n)
		direc     = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
		x, y, cur = 0, 0, 0
	)

	for i := 0; i < m*n; i++ {
		ret[i] = matrix[x][y]
		visited[x][y] = true
		nextX, nextY := x+direc[cur][0], y+direc[cur][1]
		if nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY] {
			cur = (cur + 1) % 4
		}
		x += direc[cur][0]
		y += direc[cur][1]
	}

	return ret
}

func spiralOrder1(matrix [][]int) []int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return nil
	}
	m, n := len(matrix), len(matrix[0])
	var (
		ret                   = make([]int, m*n)
		left, right, up, down = 0, n - 1, 0, m - 1
		cur                   = 0
	)

	for left <= right && up <= down {
		for i := left; i <= right; i++ {
			ret[cur] = matrix[up][i]
			cur++
		}
		for j := up + 1; j <= down; j++ {
			ret[cur] = matrix[j][right]
			cur++
		}
		if left < right && up < down {
			for i := right - 1; i >= left; i-- {
				ret[cur] = matrix[down][i]
				cur++
			}
			for j := down - 1; j > up; j-- {
				ret[cur] = matrix[j][left]
				cur++
			}
		}

		left++
		right--
		up++
		down--
	}

	return ret
}
