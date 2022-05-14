package main

import "fmt"

func main() {
	//5번째 요소를 삭제하려고 할 때의 예시 코드
	var a []int
	x := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	a = append(x[:4], x[6:]...)
	for i := 0; i < 10; i++ {
		fmt.Println(a[i])
	}
}
