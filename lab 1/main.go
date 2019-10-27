package main

import "fmt"

func main() {
  var x, y integer
  fmt.Print("Enter a number: ")
  fmt.Scanln(&x)

  fmt.Print("Enter another number: ")
  fmt.Scanln(&y)

  fmt.Printf("%d + %d = %d\n", x, y, x+y)
}
