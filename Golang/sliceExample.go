package main

import "fmt"

func main() {
	var n int = 3
	fruits := make([]string, n)
	fruits[0] = "사과"
	fruits[1] = "바나나"
	fruits[2] = "토마토"

	fmt.Println(fruits)
	fmt.Println(fruits[1:])
	fmt.Println(fruits[:3])
}
