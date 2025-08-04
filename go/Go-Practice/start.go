package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println("My favorite number is", rand.Intn(10))
	demo()
	demo1()
}

func demo(){
	fmt.Println("This is a demo line")
}