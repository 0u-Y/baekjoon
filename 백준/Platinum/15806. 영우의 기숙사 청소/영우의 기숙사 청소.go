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

type Node struct {
    r, c, d int
}



func solve() {
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m, k, t int
    fmt.Fscan(reader, &n, &m, &k, &t)

    var minTime [305][305][2]int

    for i:=1; i<=n; i++ {
        for j:=1; j<=n; j++ {
            minTime[i][j][0] = 1e9
            minTime[i][j][1] = 1e9
        }
    }

    q := make([]Node, 0, 180000)

    for i:=0; i<m; i++ {
        var r, c int
        fmt.Fscan(reader, &r, &c)
        q = append(q, Node{r, c, 0})
    }

    targets := make([][2]int, k)

    for i:=0; i<k; i++ {
        fmt.Fscan(reader, &targets[i][0], &targets[i][1])
    }

    dx := []int{-2, -2, -1, -1, 1, 1, 2, 2}
    dy := []int{-1, 1, -2, 2, -2, 2, -1, 1}

    head := 0

    for head<len(q) {
        curr := q[head]
        head++

        if curr.d == t {
            continue
        }

        nd := curr.d + 1
        np := nd%2

        for i:=0; i<8; i++ {
            nr := curr.r + dx[i]
            nc := curr.c + dy[i]

            if nr>=1 && nr<=n && nc>=1 && nc<=n {
                if minTime[nr][nc][np] > nd {
                    minTime[nr][nc][np] = nd
                    q = append(q, Node{nr, nc, nd})
                }
            }
        }
    }

    clean := false
    targetParity := t%2

    
    for _, target := range targets {
        r, c := target[0], target[1]

        if minTime[r][c][targetParity] <= t {
            clean = true
            break
        }
    }

    if clean {
        fmt.Fprintln(writer, "YES")
    } else {
        fmt.Fprintln(writer, "NO")
    }
}


func main() {
    solve()
}

