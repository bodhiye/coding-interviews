package main

import "fmt"

func main() {
	fmt.Println(firstUniqChar("leetcode"))
}

func firstUniqChar(s string) byte {
	ss := make(map[rune]int)
	for _, c := range s {
		ss[c]++
	}
	for _, c := range s {
		if ss[c] == 1 {
			return byte(c)
		}
	}
	return ' '
}

func firstUniqChar1(s string) byte {
	ss := [26]int{}
	for _, c := range s {
		ss[c-'a']++
	}
	for _, c := range s {
		if ss[c-'a'] == 1 {
			return byte(c)
		}
	}
	return ' '
}
