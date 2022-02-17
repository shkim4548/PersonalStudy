package main

import "fmt"

func main() {
	var a, b, res float64

	fmt.Scanf("%d %d", &a, &b)
	res = a / b
	fmt.Printf("%f", res)
}
