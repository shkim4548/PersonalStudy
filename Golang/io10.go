package main

import "fmt"

func main() {
	var a, b, first, second, third, res int
	fmt.Scanf("%d\n%d", &a, &b)
	first = b % 10 * a
	second = (((b % 100) - (b % 10)) * a) / 10
	third = ((b - (b % 100)) * a) / 100
	res = a * b
	fmt.Printf("%d\n%d\n%d\n%d", first, second, third, res)
}
