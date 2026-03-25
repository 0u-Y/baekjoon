package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var t int
    fmt.Fscan(reader, &t)

    for i:=0; i<t; i++ {
        var n int
        fmt.Fscan(reader, &n)

        fmt.Fprintln(writer, n * 999999999)
    }
}