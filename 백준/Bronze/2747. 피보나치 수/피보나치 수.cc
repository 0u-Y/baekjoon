#include <iostream>
#include <algorithm>


using namespace std;


int n;

int main(){
    cin>>n;

    int dp[46];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n];




}


