#include <iostream>
#include <algorithm>

using namespace std;


int t,n;
int num;


int arr[100001][2];

int dp[100001][2];





int main(){

    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;


        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin>>arr[j][i];
            }
        }

        dp[1][1] = arr[1][1];
        dp[1][2] = arr[1][2];

        dp[2][1] = dp[1][2] + arr[2][1];
        dp[2][2] = dp[1][1] + arr[2][2];

        for(int i=3; i<=n; i++){
            dp[i][1] = max(dp[i-1][2], dp[i-2][2]) + arr[i][1];
            dp[i][2] = max(dp[i-1][1], dp[i-2][1]) + arr[i][2];
        }


        cout<< max(dp[n][1], dp[n][2]) <<'\n';







    }




    





}