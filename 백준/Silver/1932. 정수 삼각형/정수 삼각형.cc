#include <iostream>


using namespace std;


int main(){
    int n;
    int num;
    cin>>n;

    int dp[501][501];
    int tri[501][501];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin>>tri[i][j];
        }
    }
    int max_sum = -1;

    dp[1][1] = tri[1][1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
        }
    }

    for(int i=1; i<=n; i++){
            max_sum = max(max_sum , dp[n][i]);
    }
    cout<<max_sum;

    



}