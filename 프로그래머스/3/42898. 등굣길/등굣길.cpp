#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 1));

    for (auto p : puddles) {
        map[p[1]][p[0]] = 0;
    }
    

    dp[1][1] = 1;
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                if (i > 1) dp[i][j] += dp[i - 1][j];
                if (j > 1) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    
    return dp[n][m];
}
