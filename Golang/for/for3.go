package main
import "fmt"

func main(){
	var a,b,c int
	fmt.Scanf("%d", &a)

	for i:=1;i<=a;i++{
		fmt.Scanf("%d %d",&b,&c)
		fmt.Printf("%d\n",b+c)
	}
}