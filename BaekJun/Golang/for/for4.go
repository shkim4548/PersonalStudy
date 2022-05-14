package main
import (
		"fmt"
		"bufio"
		"os"
		)

func main(){
	var len int
	reader:=bufio.NewReader(os.Stdin)
	writer:=bufio.NewWriter(os.Stdout)
	fmt.Fscanln(reader, &len)
	
	var a,b int

	for i:=0;i<len;i++{
		fmt.Fscanln(reader, &a, &b)
		fmt.Fprintln(writer, a+b)
	}
	writer.Flush()
}