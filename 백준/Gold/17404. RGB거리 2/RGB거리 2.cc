#include <iostream>

using namespace std;


int main(){

    int map[4][1001];

    int dp[4][1001];


    int n;
    cin>>n;


    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin>>map[j][i];
        }
    }


    int ans = 1e9;

    for(int k=1; k<=3; k++){
        
        for(int i=1; i<=3; i++){
            if(i == k){
                dp[i][1] = map[i][1];
            }
            else dp[i][1] = 1e9;
        }


        for(int i=2; i<=n; i++){
            dp[1][i] = map[1][i] + min(dp[2][i-1], dp[3][i-1]);
            dp[2][i] = map[2][i] + min(dp[1][i-1], dp[3][i-1]);
            dp[3][i] = map[3][i] + min(dp[2][i-1], dp[1][i-1]);
        }

        for(int i=1; i<=3; i++){
            if(i != k) ans = min(ans, dp[i][n]);     
        }
    }

    cout<<ans;


}