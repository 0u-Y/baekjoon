#include <iostream>

using namespace std;


int main(){

    int n,k;

    cin>>n>>k;


    int dp[1001][1001];

    for(int i=1; i<=n; i++){
        dp[i][1] = i;
        dp[i][0] = 1;
    }


    for(int i=2; i<n; i++){
        for(int j=2; j<=k; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % 1000000003;
        }
    }



    cout<<(dp[n-3][k-1] + dp[n-1][k]) % 1000000003;




}