package main

import "fmt"

func main() {
	s := "We are happy."
	fmt.Println(replaceSpace(s))
}

func replaceSpace(s string) string {
	var res = make([]byte, 0)
	for i := range s {
		if s[i] == ' ' {
			res = append(res, '%', '2', '0')
		} else {
			res = append(res, s[i])
		}
	}
	return string(res)
}
