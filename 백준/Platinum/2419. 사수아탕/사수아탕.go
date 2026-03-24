package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

const INF = int(1e15)

var (
    n, m int
    X []int
    dp [305][305][2]int
)

func min(a, b int) int {
    if a<b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}
func solve(l, r, position, remain int) int {
    if remain == 0 {
        return 0
    }

    if dp[l][r][position] != -1 {
        return dp[l][r][position]
    }

    result := INF

    currentPosition := X[l]
    if position == 1 {
            currentPosition = X[r]
    }

    if l > 0 {
        dist := currentPosition - X[l-1]
        result = min(result, solve(l-1, r, 0, remain-1) + dist * remain)
    }

    if r < len(X)-1 {
        dist := X[r+1] - currentPosition
        result = min(result, solve(l, r+1, 1, remain-1) + dist * remain)
    }

    dp[l][r][position] = result

    return result
}



func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscan(reader, &n, &m)

    flag := false

    for i:=0; i<n; i++ {
        var x int
        fmt.Fscan(reader, &x)

        X = append(X, x)
        if x == 0 {
            flag = true
        }
    }

    if !flag {
        X = append(X, 0)
    }

    sort.Ints(X)

    startIndex := 0;

    for i, v := range X {
        if v == 0 {
            startIndex = i
            break
        }
    }

    result := 0

    for k:=1; k<=n; k++ {
        for i:=0; i<len(X); i++ {
            for j:=0; j<len(X); j++ {
                dp[i][j][0] = -1
                dp[i][j][1] = -1
            }
        }

        remain := k

        if flag {
            remain = k-1
            
        }

        penalty := solve(startIndex, startIndex, 0, remain)
        profit := k*m - penalty

        result = max(result, profit)
    }

    fmt.Println(result)
}
