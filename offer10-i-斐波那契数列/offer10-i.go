package main

import (
	"fmt"
)

// 递归
var dp [101]int

func fib(n int) int {
	if n < 2 {
		return n
	}
	if dp[n] > 0 {
		return dp[n]
	}
	dp[n] = fib(n-1) + fib(n-2)
	return dp[n] % 1000000007
}

// 动态规划
func fib1(n int) int {
	a, b := 0, 1
	for i := 0; i < n; i++ {
		a, b = b, (a+b)%1000000007
	}
	return a
}

// 矩阵快速幂
func fib2(n int) int {
	if n < 2 {
		return n
	}

	first := [][2]int{{2, 1}, {1, 0}}
	m := [][2]int{{1, 1}, {1, 0}}
	res := matrixPow(m, n-1)
	return matrixMul(first, res)[1][1]
}

func matrixPow(x [][2]int, n int) [][2]int {
	res := x
	for n != 0 {
		if n&1 == 1 { // 奇偶分治
			res = matrixMul(res, x)
		}
		x = matrixMul(x, x)
		n >>= 1
	}
	return res
}

func matrixMul(x, y [][2]int) [][2]int {
	m := make([][2]int, 2)
	m[0][0] = (x[0][0]*y[0][0] + x[0][1]*y[1][0]) % 1000000007
	m[0][1] = (x[0][0]*y[0][1] + x[0][1]*y[1][1]) % 1000000007
	m[1][0] = (x[1][0]*y[0][0] + x[1][1]*y[1][0]) % 1000000007
	m[1][1] = (x[1][0]*y[0][1] + x[1][1]*y[1][1]) % 1000000007
	return m
}

func main() {
	fmt.Println(fib(100))
	fmt.Println(fib1(100))
	fmt.Println(fib2(100))
}
