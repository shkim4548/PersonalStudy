package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)
	var res1 int = (a + b) % c
	var res2 int = ((a % c) + (b % c)) % c
	var res3 int = (a * b) % c
	var res4 int = ((a % c) * (b % c)) % c
	fmt.Printf("%d\n%d\n%d\n%d", res1, res2, res3, res4)
}
