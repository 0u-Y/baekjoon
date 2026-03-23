package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    writer *bufio.Writer
    reader *bufio.Reader
)

func solve() {
    var a, b, c int

    for {
        fmt.Fscan(reader, &a, &b, &c)

        if a == 0 && b == 0 && c == 0 {
            break
        }

         maxSide := a

        if b > maxSide {
            maxSide = b 
        }

        if c > maxSide {
            maxSide = c
        }

        sum := a + b + c

        if maxSide >= sum - maxSide {
            fmt.Fprintln(writer, "Invalid")
            continue
        }

        if a == b && b == c {
            fmt.Fprintln(writer, "Equilateral")
        } else if a == b || b == c || a == c {
            fmt.Fprintln(writer, "Isosceles")
        } else {
            fmt.Fprintln(writer, "Scalene")
        }
    }
}

func main() {
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    solve()

}