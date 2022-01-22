package main

import "fmt"

func main() {
	s := "abc"
	ps := &s
	s += "def"
	fmt.Println(s)  //s는 Value타입이니까 그냥 해도 나오는거고
	fmt.Println(ps) //ps는 포인터 타입이니까 역참조 안하면 주소값이 나온다.
}
