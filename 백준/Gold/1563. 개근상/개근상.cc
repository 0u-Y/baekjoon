#include <iostream>

using namespace std;


const int mod = 1000000;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1001][3][4];
    // 1 : 날짜, 2 : 지각 , 3 : 결석

    int n;
    cin>>n;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % mod;
        dp[i][0][1] = dp[i-1][0][0] % mod;
        dp[i][0][2] = dp[i-1][0][1] % mod;
        dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % mod;
        dp[i][1][1] = dp[i-1][1][0] % mod;
        dp[i][1][2] = dp[i-1][1][1] % mod;
    }

    int result= (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod;


    cout<<result;



}